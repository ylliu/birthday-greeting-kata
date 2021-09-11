//
// Created by youlong on 2021/9/11.
//

#include <iostream>
#include "MailSender.h"

void MailSender::sendMessage(Employee &employee) {
    SmtpMessage smtpMessage = constructMessage(employee);
    //smtp->send(smtpMessage);
    smtpMessage.logMessage();
}

SmtpMessage MailSender::constructMessage(Employee employee) {
    std::string subject = "Happy Birthday!";
    std::string body = "Happy Birthday, dear " + employee.getFirstName() + "!";
    std::string sender = "sender@gmail.com";
    std::string receiver = employee.getEmail();
    return SmtpMessage(subject, body, sender, receiver);
}
