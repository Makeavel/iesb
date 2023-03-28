
import random
import math

# Parâmetros do algoritmo genético
POPULATION_SIZE = 100
GENE_LENGTH = 10
MUTATION_RATE = 0.1
NUM_GENERATIONS = 100

def create_individual():
    # Cria um indivíduo aleatório com valores entre 0 e 5.12 (intervalo sugerido para a função Rastrigin)
    return [max(round(random.uniform(0, 5.12), 2), 0) for _ in range(GENE_LENGTH)]

def create_population():
    # Cria uma população aleatória de indivíduos
    return [create_individual() for _ in range(POPULATION_SIZE)]

def rastrigin(x):
    n = len(x)
    A = 10
    return A * n + sum([(xi ** 2 - A * math.cos(2 * math.pi * xi)) for xi in x])

def fitness(individual):
    # Calcula a aptidão do indivíduo usando a função de avaliação
    return -rastrigin(individual)

def selection(population):
    # Seleciona dois indivíduos aleatórios da população, usando seleção por torneio
    # Essa é uma implementação simples que seleciona dois indivíduos aleatórios e escolhe o melhor deles como pai/mãe
    parent1 = max(random.sample(population, 10), key=fitness)
    parent2 = max(random.sample(population, 10), key=fitness)
    return parent1, parent2

def crossover(parent1, parent2):
    # Realiza o crossover entre dois pais para produzir dois filhos
    # Essa é uma implementação simples que seleciona um ponto de corte aleatório e troca os segmentos de cada pai
    crossover_point = random.randint(1, GENE_LENGTH - 1)
    child1 = parent1[:crossover_point] + parent2[crossover_point:]
    child2 = parent2[:crossover_point] + parent1[crossover_point:]
    return child1, child2

def mutate(individual):
    # Aplica uma mutação aleatória a um indivíduo, com uma chance definida pela taxa de mutação
    # Essa é uma implementação simples que adiciona ou subtrai um valor aleatório de cada gene do indivíduo
    for i in range(GENE_LENGTH):
        if random.random() < MUTATION_RATE:
            individual[i] += random.uniform(-0.1, 0.1)
            individual[i] = max(round(individual[i], 2), 0)
    return individual

def evolve_population(population):
    # Evolui a população por uma geração, aplicando seleção, crossover e mutação
    new_population = []
    while len(new_population) < POPULATION_SIZE:
        parent1, parent2 = selection(population)
        child1, child2 = crossover(parent1, parent2)
        new_population.append(mutate(child1))
        new_population.append(mutate(child2))
    return new_population

# Cria a população inicial e avalia a aptidão
population = create_population()
fitnesses = [fitness(individual) for individual in population]

# Evolve the population for a fixed number of generations
for i in range(NUM_GENERATIONS):
    # Select the fittest individuals for display
    fittest_individual = max(population, key=fitness)
    fittest_fitness = fitness(fittest_individual)
    avg_fitness = sum(fitnesses) / len(fitnesses)

    # Display information about the current generation
    print(f"Generation {i+1}: Average Fitness = {avg_fitness:.2f}, Fittest Fitness = {fittest_fitness:.2f}, Fittest Individual = {fittest_individual}")

    # Evolve the population to the next generation
    population = evolve_population(population)
    fitnesses = [fitness(individual) for individual in population]