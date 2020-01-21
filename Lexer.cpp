
#include "Lexer.h"
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include "Lexer.h"
#include <regex>

using namespace std;

vector<string> Lexer::get_lexer() {
    return this->cur_lex;
}

vector<string> Lexer::split_from_file(string fileName) {
    vector<string> vector;
    string tmp;
    fstream file;
    if (!file.is_open()) {
        file.open(fileName, fstream::in | fstream::app);
    }
    while (getline(file,tmp)) {
        vector.push_back(tmp);
    }
    file.close();
    return fromStringToExp(vector);
}
/**
 * @param the lines in the file.
 * @return vector of words in the right order
 */
vector<string> Lexer::fromStringToExp(vector<string> commands) {
    vector<string> words;
    bool check;
    string s;
    // goes all the lines in the file.
    for (auto const item:commands) {
        // if there is a '=' in the line.
        if (item.find('=') != std::string::npos) {
            check = false;
            std::stringstream ss(item);
            // split by '='.
            while (std::getline(ss, s, '=')) {
                std::stringstream sd(s);
                // split by space.
                if(!check) {
                    while (std::getline(sd, s, ' ')) {
                        if(!s.empty() && s.at(0) == '\t') {
                            s.erase(std::remove(s.begin(),s.end(), '\t'), s.end());
                        }
                        words.push_back(s);
                    }

                }
                else{
                    string sb= s.substr(0,5);
                    if(s.substr(0,5) == " bind") {
                        words.push_back(s.substr(0,5));
                        words.push_back(s.substr(6,s.length()-1));
                    }
                    else words.push_back(s);
                }
                if (!check) {
                    check = true;
                    // if there is no '=' in the vector of words, put it.
                    words.push_back("=");
                }
            }
            // if there is no '=' in line but there is ,
        } //else if(item.find('=') != std::string::npos) {
            //std::stringstream ss;
            //}
        else {
            std::stringstream ss(item);
            string help;
            // split by space.
            while (std::getline(ss, s, ' ')) {
                if(!s.empty() && s.at(0) == '\t') {
                    s.erase(std::remove(s.begin(),s.end(), '\t'), s.end());
                }
                // if help isn't empty and s isn't empty and s is a number and the last index of help is also a number
                if(!s.empty() && isdigit(s.at(0)) && !help.empty()) {
                    // push the help
                    words.push_back(help);
                    // empty the string help.
                    help = "";
                    // push the string.
                    words.push_back(s);
                }
                    // if s is not a space, and it's number and we didn't reach the  final of the line
                    //else if(!s.empty() && isdigit(s.at(0)) && !ss.eof()) {
                    //help += s;
                    //}
                    // if help isn't empty and it isn't operator , just concatenating the string to help.
                else if(!help.empty() && isOperator(s))
                    help+=s;
                else
                if(help.empty()) words.push_back(s);
            }
        }
    }
    vector<string> final;
    for (auto const &item:words) {
        if(item == "") continue;
        final.push_back(item);
    }
    // return the vector of string.
    return final;
}
/**
 * @param c the expression.
 * @return return 1 if is operator, 0 otherwise.
 */
bool Lexer::isOperator(string & c) {
    return(c == "+" || c == "-" || c == "*" || c == "=" || c == "/"  );
}

vector<string> Lexer::split_from_command_line() {
    bool keep=true;
    string tmp,line,nline="";
    char c;
    while(keep) {
        cout << "Please enter new command line"<<endl;
        cin >> ws;
        getline(cin, line);
        stringstream ss(line);
        while (ss.good()) {
            ss >> tmp;
            nline="";
            for (int i = 0; i < tmp.size(); i++) {
                c = tmp[i];
                if (c>=0&&c<=127) {
                    nline += c;
                } else {
                    continue;
                }
            }
            cur_lex.push_back(tmp);
        }
        cout<<"Command added successfully."<<endl;
        cout<<"Do you want to enter another command ? y/n"<<endl;
        cin>>c;
        if(c=='n'){
            keep = false;
        }else if(c!='y'){
            perror("invalid argument");
            exit(1);
        }
    }
}