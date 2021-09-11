//
// Created by youlong on 2021/9/11.
//

#ifndef BIRTHDAYGREETING3_MAILSENDER_H
#define BIRTHDAYGREETING3_MAILSENDER_H


#include <string>
#include "Employee.h"
#include "SmtpMessage.h"
#include "GreetingSender.h"

class MailSender : public GreetingSender {

public:
    void sendMessage(Employee &employee) override;

    SmtpMessage constructMessage(Employee employee);
};


#endif //BIRTHDAYGREETING3_MAILSENDER_H
