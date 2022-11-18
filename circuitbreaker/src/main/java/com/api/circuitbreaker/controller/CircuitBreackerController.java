package com.api.circuitbreaker.controller;

import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;
import org.springframework.web.reactive.function.client.WebClient;

import reactor.core.publisher.Mono;

@RestController
@RequestMapping("/")
public class CircuitBreackerController {

    @GetMapping("/home")
    public Mono<String> readingList(){
        return Mono.just(null);
    }

    @GetMapping("/read")
    public Mono<String> read(){
        return WebClient.builder().build().get()
        .uri("http://localhost:8081/home").retrieve()
        .bodyToMono(String.class);
    }


}
