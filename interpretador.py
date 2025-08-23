import pandas as pd
import csv

list=[]
nomeExcel = "baseDadosTv.txt"


with open(nomeExcel, "rt") as arquivoCSV:
    objectCSV = csv.reader(arquivoCSV, delimiter=';')


