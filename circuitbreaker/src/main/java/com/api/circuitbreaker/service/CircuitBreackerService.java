package com.api.circuitbreaker.service;

import reactor.core.publisher.Mono;

public interface CircuitBreackerService {
    
    void CircuitBreackerServiceImpl();
    Mono<String> readList();

}
