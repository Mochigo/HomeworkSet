package com.homework.hotel.bean;

import javax.validation.constraints.Email;
import javax.validation.constraints.NotBlank;

public class Mail {
    @Email
    private String email;

    public Mail(String email) {
        this.email = email;
    }

    public String getEmail() {
        return email;
    }

    public void setEmail(String email) {
        this.email = email;
    }
}
