//
// Created by youlong on 2021/9/11.
//

#ifndef BIRTHDAYGREETING3_SMTPMESSAGE_H
#define BIRTHDAYGREETING3_SMTPMESSAGE_H


#include <string>

class SmtpMessage {

public:
    SmtpMessage(std::string subject, std::string body, std::string sender, std::string receiver);

    void logMessage();

private:
    std::string subject;
    std::string body;
    std::string sender;
    std::string receiver;
};


#endif //BIRTHDAYGREETING3_SMTPMESSAGE_H
