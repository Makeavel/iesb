package com.api.circuitbreaker.service;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import reactor.core.publisher.Mono;
import org.springframework.cloud.client.circuitbreaker.ReactiveCircuitBreaker;
import org.springframework.cloud.client.circuitbreaker.ReactiveCircuitBreakerFactory;
import org.springframework.stereotype.Service;
import org.springframework.web.reactive.function.client.WebClient;

@Service
public class CircuitBreackerServiceImpl implements CircuitBreackerService{
    
    private static final Logger log = LoggerFactory.getLogger(CircuitBreackerServiceImpl.class);

    private  WebClient webClient;
    private  ReactiveCircuitBreaker reactiveCircuitBreaker;
    private  ReactiveCircuitBreakerFactory createreactiveFactory;

    public void CircuitBreackerServiceImpl( ){
        this.webClient = WebClient.builder().baseUrl("http://localhost:8081").build();
        this.reactiveCircuitBreaker = createreactiveFactory.create("home");
    }

    public Mono<String> readList(){
        return reactiveCircuitBreaker.run(
            webClient.get().uri("/home")
            .retrieve().bodyToMono(String.class), throwable -> {
                log.warn("F", throwable);
                return Mono.just("Foi");
            });
    }

}
