package com.homework.hotel.Interceptor;

import org.springframework.web.servlet.HandlerInterceptor;

import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

public class LoginInterceptor implements HandlerInterceptor {
    @Override
    public boolean preHandle(HttpServletRequest request, HttpServletResponse response, Object handler) throws Exception {
        Object login_user = request.getSession().getAttribute("login_user");
        if (login_user == null) {
            request.getRequestDispatcher("/").forward(request, response);
            request.setAttribute("msg", "没有登录请先登录");
            return false;
        } else {
            return true;
        }

    }
}
