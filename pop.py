import random

POPULATION_SIZE = 100  # tamanho da população
NUM_GENES = 5  # número de genes que cada indivíduo tem
MAX_GENERATIONS = 1000  # número máximo de gerações
MUTATION_RATE = 0.1  # taxa de mutação

# Definição das funções

def generate_random_individual():
    # Gera um indivíduo aleatório com 5 genes de aprendizagem
    individual = [random.randint(0, 100) for _ in range(NUM_GENES)]
    return individual

def generate_random_population():
    # Gera uma população aleatória de 100 indivíduos
    population = [generate_random_individual() for _ in range(POPULATION_SIZE)]
    return population

def evaluate_fitness(individual):
    # Avalia a aptidão de um indivíduo baseado na média das notas
    fitness = sum(individual) / NUM_GENES
    return fitness

def tournament_selection(population):
    # Seleciona um indivíduo aleatório através do torneio entre 3 indivíduos da população
    competitors = random.sample(population, 3)
    competitors_fitness = [evaluate_fitness(individual) for individual in competitors]
    winner_index = competitors_fitness.index(max(competitors_fitness))
    winner = competitors[winner_index]
    return winner

def crossover(parent1, parent2):
    # Realiza a reprodução dos pais através do crossover de um ponto
    crossover_point = random.randint(1, NUM_GENES - 1)
    child = parent1[:crossover_point] + parent2[crossover_point:]
    return child

def mutation(individual):
    # Realiza a mutação de um gene com probabilidade MUTATION_RATE
    for i in range(NUM_GENES):
        if random.random() < MUTATION_RATE:
            individual[i] = random.randint(0, 100)

def generate_next_generation(population):
    # Gera a próxima geração a partir da seleção de pais e da reprodução
    next_generation = []
    for i in range(POPULATION_SIZE):
        parent1 = tournament_selection(population)
        parent2 = tournament_selection(population)
        child = crossover(parent1, parent2)
        mutation(child)
        next_generation.append(child)
    return next_generation

def generate_random_individual_with_unrepeated_marks():
    # Gera um indivíduo aleatório com 5 notas randômicas não repetidas
    individual = []
    while len(individual) < NUM_GENES:
        note = random.randint(0, 100)
        if note not in individual:
            individual.append(note)
    return individual

def main():
    # Gera a população inicial e avalia sua aptidão
    population = generate_random_population()
    for individual in population:
        fitness = evaluate_fitness(individual)

    # Repete o processo de seleção e reprodução por um número máximo de gerações
    for generation in range(MAX_GENERATIONS):
        # Gera a próxima geração e avalia sua aptidão
        next_generation = generate_next_generation(population)
        for individual in next_generation:
            fitness = evaluate_fitness(individual)

        # Seleciona os melhores indivíduos para a próxima geração
        population = sorted(next_generation, key=evaluate_fitness, reverse=True)[:POPULATION_SIZE]

        # Gera um indivíduo
    # Gera um indivíduo randômico com notas não repetidas
    random_individual = generate_random_individual_with_unrepeated_marks()

    # Verifica se o indivíduo já está na população e o adiciona se não estiver
    if random_individual not in population:
        population.pop()
        population.append(random_individual)
    
    # Imprime o melhor indivíduo da geração atual
    best_individual = max(population, key=evaluate_fitness)
    print(f"Melhor indivíduo da geração {generation}: {best_individual} com aptidão {evaluate_fitness(best_individual)}")
