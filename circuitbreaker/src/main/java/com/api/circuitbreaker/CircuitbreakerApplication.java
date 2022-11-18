package com.api.circuitbreaker;

import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;

@SpringBootApplication
public class CircuitbreakerApplication {

	//https://spring.io/projects/spring-cloud-circuitbreaker
	//https://spring.io/guides/gs/cloud-circuit-breaker
	//https://www.google.com/search?q=como+implementar+circuit+break+spring+boot&rlz=1C1GCEU_pt-BRBR981BR982&oq=como+implementar+circuit+break+spring+boot&aqs=chrome..69i57j33i10i160l4.10696j0j7&sourceid=chrome&ie=UTF-8
	public static void main(String[] args) {
		SpringApplication.run(CircuitbreakerApplication.class, args);
	}

}


