import random

methodologies = ['Aprendizagem baseada em problemas','Aprendizagem baseada em experiências','Ensino tradicional','Aprendizagem baseada em projetos ','Aprendizagem cooperativa']

def create_individual():
    return random.choice(methodologies)

def calculate_fitness(individual, student_data):
    avg_grade = sum(student_data['notas']) / len(student_data['notas'])
    if student_data['preferencia'] == 'pratica_em_grupo' and individual == 'pratica_em_grupo':
        fitness = avg_grade + 10
    elif student_data['preferencia'] == 'estudo_dirigido' and individual == 'estudo_dirigido':
        fitness = avg_grade + 10
    else:
        fitness = avg_grade
    return fitness

def selection(population, student_data):
    selected = random.choices(population, weights=[calculate_fitness(ind, student_data) for ind in population], k=2)
    return selected

def crossover(parents):
    return random.choice(parents)

def mutate(method):
    other_methods = [m for m in methodologies if m != method]
    return random.choice(other_methods)

def genetic_algorithm(student_data, generations, population_size):
    population = [create_individual() for _ in range(population_size)]
    for _ in range(generations):
        new_population = []
        for _ in range(population_size):
            parents = selection(population, student_data)
            child = crossover(parents)
            mutated_child = mutate(child)
            new_population.append(mutated_child)
        population = new_population
    best_individual = max(population, key=lambda ind: calculate_fitness(ind, student_data))
    return best_individual

def generate_student_data(num_students):
    names = ["MARCOS", "ANA", "CARLA", "GABRIELA", "MARIA", "JOSÉ", "JÚLIA", "GUSTAVO", "RAFAEL", "GABRIEL", "JOÃO", "LUÍS", "LUIZ", "LUCAS", "MATEUS", "FELIPE", "MARIANA", "FERNANDA", "FABIANA", "GABRIELLE", "JULIANA", "JOSIANE", "RODRIGO", "JOSÉ CARLOS", "CARLOS", "ROBERTO", "ROBERTA", "MARCIA", "MÁRCIO", "FÁBIO", "FELIPE", "JULIO", "JULIANO", "MARCELO", "RICARDO", "MARCO", "GUILHERME", "LARISSA", "LETÍCIA", "LEANDRO", "LEONARDO", "PAULA", "PAULO", "PEDRO", "LUIZA", "BÁRBARA", "BRUNA", "BRUNO", "CAMILA", "ISABELA", "ISABEL", "SARA", "SARAH", "SILVANA", "SILVIA", "TATIANA", "TALITA", "THAIS", "THAÍS", "VINÍCIUS", "WILLIAM", "YASMIN", "YASMIM", "ALINE", "ANDRÉ", "ANDRÉA", "ÂNGELA", "ANGELA", "ANTÔNIA", "ANTONIO", "ARTHUR", "BEATRIZ", "BRENO", "CAIO", "CAMILA", "CARMEN", "CECÍLIA", "CÍCERO", "CLARA", "CLAUDIA", "CLEIDE", "CRISTIANE", "CRISTINA", "DANIEL", "DANIELE", "DANIELA", "DANIELLE", "DAVI", "DÉBORA", "EDUARDA", "EDUARDO", "ELAINE", "ELIANE", "ELISA", "ELIZABETH", "EMANUEL", "EMANUELE", "EMILIA", "ENZO", "ERIC", "ERICA", "ERIKA", "ESTER", "FABRÍCIO", "FELIPE", "FERNANDO", "FLÁVIA", "GABRIELA", "GUILHERME", "HENRIQUE", "IARA", "ISABELLA", "IZABELA", "JAIME", "JEAN", "JESSICA", "JÉSSICA", "JOANA", "JONAS", "JORGE", "JOSEANE", "JOSÉ EDUARDO", "JOSÉ LUIZ", "JOYCE", "JULIANA", "KAREN", "KARINA", "KARINE", "KELLY", "LAÍS", "LARA", "LAURA", "LEILA", "LIGIA", "LILIAN", "LÍVIA", "LORENA", "LUANA", "LUCIA", "LUCIANA", "LUCIENE"]
    random.shuffle(names)
    students_data = []
    for i in range(num_students):
        student = {
            'nome': names[i],
            'idade': random.randint(14, 18),
            'notas': [random.uniform(0, 10) for _ in range(3)],
            'preferencia': random.choice(['Aprendizagem baseada em problemas','Aprendizagem baseada em experiências','Ensino tradicional','Aprendizagem baseada em projetos ','Aprendizagem cooperativa'])
        }
        students_data.append(student)
    return students_data

students_data = generate_student_data(100)
generations = 100
population_size = 50

# Encontrando a melhor metodologia para cada aluno individualmente
best_methodologies = []
for student_data in students_data:
    best_methodology = genetic_algorithm(student_data, generations, population_size)
    best_methodologies.append((student_data['nome'], best_methodology))

# Exibindo todos os alunos e suas melhores metodologias
for name, methodology in best_methodologies:
    print(f"Melhor metodologia de ensino para {name}: {methodology}")
