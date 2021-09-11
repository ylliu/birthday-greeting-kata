//
// Created by youlong on 2021/9/11.
//

#include <fstream>
#include <iostream>
#include "SmtpMessage.h"
#include "../lib/json/json.h"

SmtpMessage::SmtpMessage(std::string subject, std::string body, std::string sender, std::string receiver) {
    this->subject = subject;
    this->body = body;
    this->sender = sender;
    this->receiver = receiver;
}

void SmtpMessage::logMessage() {
    std::ofstream greetings;
    greetings.open("greetings.json");
    if (!greetings) {
        std::cerr << "Can't open greetings.log" << std::endl;
    }
    Json::Value greetingItem;
    greetingItem["Subject"] = subject;
    greetingItem["From"] = sender;
    greetingItem["To"] = receiver;
    greetingItem["Body"] = body;
    greetings << greetingItem.toStyledString();
    greetings.close();
}


