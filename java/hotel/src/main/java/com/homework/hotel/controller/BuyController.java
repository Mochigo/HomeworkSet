package com.homework.hotel.controller;

import com.homework.hotel.service.BuyService;
import org.springframework.stereotype.Controller;

import javax.annotation.Resource;

@Controller
public class BuyController {

    @Resource
    BuyService buyService;
}
