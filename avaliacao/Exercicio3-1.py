import random


# Parâmetros do algoritmo genético
POPULATION_SIZE = 100
GENE_LENGTH = 10
MUTATION_RATE = 0.1
NUM_GENERATIONS = 100

def create_individual():
    # Cria um indivíduo aleatório com valores entre -5.12 e 5.12 (intervalo sugerido para a função Rastrigin)
    return [random.uniform(-5.12, 5.12) for _ in range(GENE_LENGTH)]

def create_population():
    # Cria uma população aleatória de indivíduos
    return [create_individual() for _ in range(POPULATION_SIZE)]

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
    # Realiza o crossover entre os dois pais, gerando dois filhos
    # Essa é uma implementação simples que realiza o crossover de um único ponto
    crossover_point = random.randint(1, GENE_LENGTH - 1)
    child1 = parent1[:crossover_point] + parent2[crossover_point:]
    child2 = parent2[:crossover_point] + parent1[crossover_point:]
    return child1, child2

def mutate(individual):
    # Realiza a mutação do indivíduo, alterando aleatoriamente um gene com uma probabilidade MUTATION_RATE
    for i in range(GENE_LENGTH):
        if random.random() < MUTATION_RATE:
            individual[i] += random.uniform(-0.5, 0.5)
    return individual

def evolve_population(population):
    # Gera uma nova população a partir da população atual, utilizando seleção, crossover e mutação
    new_population = []
    while len(new_population) < POPULATION_SIZE:
        parent1, parent2 = selection(population)
        child1, child2 = crossover(parent1, parent2)
        new_population.extend([mutate(child1), mutate(child2)])
    return new_population[:POPULATION_SIZE]

# Inicializa a população
population = create_population()

# Evolui a população por NUM_GENERATIONS gerações
for generation in range(NUM_GENERATIONS):
    population = evolve_population(population)
    best_individual = max(population, key=fitness)
    print("Generation:", generation+1, "Best individual:", best_individual, "Fitness:", fitness(best_individual))
