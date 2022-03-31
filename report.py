###############################################################
# Подключаем библеотеки для работы с excel и массивами данных #
###############################################################

import xlsxwriter
import numpy as np
import os
import math
import pandas as pd

#########################################################
# Создаем файл xlsx с листами для данных и для графиков #
#########################################################
workbook = xlsxwriter.Workbook('отчет.xlsx')
worksheet = workbook.add_worksheet('Данные')
worksheet2 = workbook.add_worksheet('Графики')

######################################################################################################################
# Считываем данные в массивы из файлов data.tsv и intermediate.tsv, удаляем nan элементы из данных  intermediate.tsv #
######################################################################################################################

data = np.loadtxt("data.tsv", delimiter='\t', dtype=np.longdouble )
data_integral = np.genfromtxt("intermediate.tsv", delimiter='\t', dtype=np.longdouble )
data_integral[np.isnan(data_integral)] = 0.0
data_integral = [x[:-1].tolist() for x in data_integral]

###########################################################
# Заполняем шапку и данные главной таблицы в виде массива #
###########################################################

main_table_data = {'Интеграл от:': ['Метод трапеций',  'Метод центральных прямоугольников' ,  'Метод Симпсона'],

           'sin(x) dx': data[1],
           'cos(x) dx': data[2],
           '2*x² dx': data[3],
           'x dx': data[4],
           '5ᵡ dx': data[5],
           '1/5²+x² dx': data[6],
           'eᵡ dx': data[7],
           '(x+2)³ dx': data[8],
           }

limits_table_data = {'Границы': ['Нижняя(a)',  'Верхняя(b)', 'Точность'],
                     '':data[0],

         }

#######################################################################################
# Просчитываем значения функций и их первообразных в заданных границах интегрирования #
#######################################################################################

y = []
F_y=[]

x = []
for j in range(8):
    y.append([])
    F_y.append([])
for i in np.arange(data[0][0], data[0][1], data[0][2]):
         y[0].append(round(math.sin(round(i,1)), 6))
         F_y[0].append(round(-math.cos(round(i,1)),6))
         y[1].append(round(math.cos(round(i,1)),6))
         y[2].append(round(2*(round(i,1)*round(i,1)),6))
         F_y[2].append(round((2*(round(i,1)**3))/3,6))
         y[3].append(round(i,1))
         F_y[3].append(round((round(i,1)*round(i,1))/2,6))
         y[4].append(round(5**round(i,1),6))
         F_y[4].append(round((5**round(i,1))/math.log(5),6))
         y[5].append(round(1/(5*5+round(i,1)*round(i,1)),6))
         F_y[5].append(round(math.atan(round(i,1)/5)/5,6))
         y[6].append(round(math.exp(round(i,1)),6))
         y[7].append(round((round(i,1)+2)**3,6))
         F_y[7].append(round(((round(i,1)+2)**4)/4,6))
         x.append(round(i,1))
F_y[1]=y[0]
F_y[6]=y[6]


#######################################################################
# Заполняем шапку и данные таблицы построения графиков в виде массива #
#######################################################################

graph_table = {  'x': x,
                'y=sin(x)': y[0],
                'sin(x) dx': data_integral[0],
                'F(sin(x))': F_y[0],
                'y=cos(x)': y[1],
                'cos(x) dx': data_integral[1],
                'F(cos(x))': F_y[1],
                'y=2*x²': y[2],
                '2*x² dx': data_integral[2],
                'F(2*x²)': F_y[2],
                'y=x': y[3],
                'x dx': data_integral[3],
                'F(x)': F_y[3],
                'y=5ᵡ': y[4],
                '5ᵡ dx': data_integral[4],
                'F(5ᵡ)': F_y[4],
                'y=1/5²+x²': y[5],
                '1/5²+x² dx': data_integral[5],
                'F(1/5²+x²)': F_y[5],
                'y=eᵡ': y[6],
                'eᵡ dx': data_integral[6],
                'F(eᵡ)': F_y[6],
                'y=(x+2)³': y[7],
                '(x+2)³ dx': data_integral[7],
                'F((x+2)³)': F_y[7],
              

    
    }

########################################
# Рендерим главную таблицу результатов #
########################################

row = 0
col = 0

worksheet.set_column(0, 16, 40)
worksheet.set_row(0, 20) 
cell_format = workbook.add_format()
   
cell_format.set_align('center')
cell_format.set_align('vcenter')
cell_format.set_border()
cell_format.set_font_size(12)
col_num = 0

for key, value in main_table_data.items():
    worksheet.write(0, col_num, key, cell_format)
    worksheet.write_column(1, col_num, value, cell_format)
    col_num += 1

col_num = 0
worksheet.merge_range('A6:B6',list(limits_table_data.keys())[0], cell_format)

for key, value in limits_table_data.items():
    worksheet.write_column(6, col_num, value, cell_format)
    col_num += 1

col_num = 0

#############################
# Рендерим таблицу графиков #
#############################

for key, value in graph_table.items():
    worksheet.write(11, col_num, key, cell_format)
    worksheet.write_column(12, col_num, value, cell_format)
    col_num += 1

 

#############################################################################
# Определяем количество строк и колонок занятых данными (с учетом отступов) #
#############################################################################

df1 = pd.DataFrame(graph_table)

df2 = pd.DataFrame(main_table_data)

df3 = pd.DataFrame(limits_table_data)

max_row1, max_col1 = df1.shape
max_row2, max_col2 = df2.shape
max_row3, max_col3 = df3.shape
max_row = max_row1+max_row2+max_row3+5



############################
# Рендерим график y=sin(x) #
############################

sin_x= workbook.add_chart({'type': 'line'})


sin_x.add_series({
    'name':       '=Данные!$B$12',
    'categories': ['Данные', 12, 0, max_row, 0],
    'values':     ['Данные', 12, 1, max_row, 1],
})


sin_x_dx = workbook.add_chart({'type': 'column'})


sin_x_dx.add_series({
     'name':       '=Данные!$C$12',
    'categories':  ['Данные', 12, 0, max_row, 0],
   'values':     ['Данные', 12, 2, max_row, 2],
})


sin_x.add_series({
    'name':       '=Данные!$D$12',
    'categories': ['Данные', 12, 0, max_row, 0],
    'values':     ['Данные', 12, 3, max_row, 3],
})

sin_x_dx.combine(sin_x)


sin_x_dx.set_title({ 'name': 'График sin(x) /sin(x) dx / F(sin(x))'})


worksheet2.insert_chart('B2', sin_x_dx)


############################
# Рендерим график y=cos(x) #
############################

cos_x= workbook.add_chart({'type': 'line'})


cos_x.add_series({
    'name':       '=Данные!$E$12',
    'categories': ['Данные', 12, 0, max_row, 0],
    'values':     ['Данные', 12, 4, max_row, 4],
})

cos_x_dx = workbook.add_chart({'type': 'column'})


cos_x_dx.add_series({
    'name':       '=Данные!$F$12',
    'categories':  ['Данные', 12, 0, max_row, 0],
    'values':     ['Данные', 12, 5, max_row, 5],
})

cos_x.add_series({
    'name':       '=Данные!$G$12',
    'categories': ['Данные', 12, 0, max_row, 0],
    'values':     ['Данные', 12, 6, max_row, 6],
})

cos_x_dx.combine(cos_x)



cos_x_dx.set_title({ 'name': 'График cos(x) / cos(x) dx / F(cos(x))'})


worksheet2.insert_chart('K2', cos_x_dx)

##########################
# Рендерим график y=2*x² #
##########################

f3_x= workbook.add_chart({'type': 'line'})


f3_x.add_series({
    'name':       '=Данные!$H$12',
    'categories': ['Данные', 12, 0, max_row, 0],
    'values':     ['Данные', 12, 7, max_row, 7],
})

f3_x_dx = workbook.add_chart({'type': 'column'})


f3_x_dx.add_series({
    'name':       '=Данные!$I$12',
    'categories':  ['Данные', 12, 0, max_row, 0],
    'values':     ['Данные', 12, 8, max_row, 8],
})

f3_x.add_series({
    'name':       '=Данные!$J$12',
    'categories': ['Данные', 12, 0, max_row, 0],
    'values':     ['Данные', 12, 9, max_row, 9],
})

f3_x_dx.combine(f3_x)


f3_x_dx.set_title({ 'name': 'График 2*x² / 2*x² dx / F(2*x²)'})


worksheet2.insert_chart('B18', f3_x_dx)

#######################
# Рендерим график y=x #
#######################

f4_x= workbook.add_chart({'type': 'line'})


f4_x.add_series({
    'name':       '=Данные!$K$12',
    'categories': ['Данные', 12, 0, max_row, 0],
    'values':     ['Данные', 12, 10, max_row, 10],
})

f4_x_dx = workbook.add_chart({'type': 'column'})


f4_x_dx.add_series({
    'name':       '=Данные!$L$12',
    'categories':  ['Данные', 12, 0, max_row, 0],
    'values':     ['Данные', 12, 11, max_row, 11],
})

f4_x.add_series({
    'name':       '=Данные!$M$12',
    'categories': ['Данные', 12, 0, max_row, 0],
    'values':     ['Данные', 12, 12, max_row, 12],
})

f4_x_dx.combine(f4_x)


f4_x_dx.set_title({ 'name': 'График x / x dx / F(x)'})


worksheet2.insert_chart('K18', f4_x_dx)

########################
# Рендерим график y=5ᵡ #
########################

f5_x= workbook.add_chart({'type': 'line'})


f5_x.add_series({
    'name':       '=Данные!$N$12',
    'categories': ['Данные', 12, 0, max_row, 0],
    'values':     ['Данные', 12, 13, max_row, 13],
})

f5_x_dx = workbook.add_chart({'type': 'column'})


f5_x_dx.add_series({
    'name':       '=Данные!$O$12',
    'categories':  ['Данные', 12, 0, max_row, 0],
    'values':     ['Данные', 12, 14, max_row, 14],
})

f5_x.add_series({
    'name':       '=Данные!$P$12',
    'categories': ['Данные', 12, 0, max_row, 0],
    'values':     ['Данные', 12, 15, max_row, 15],
})

f5_x_dx.combine(f5_x)



f5_x_dx.set_title({ 'name': 'График 5ᵡ / 5ᵡ dx / F(5ᵡ)'})


worksheet2.insert_chart('B34', f5_x_dx)

#############################
# Рендерим график y=1/5²+x² #
#############################

f6_x= workbook.add_chart({'type': 'line'})


f6_x.add_series({
    'name':       '=Данные!$Q$12',
    'categories': ['Данные', 12, 0, max_row, 0],
    'values':     ['Данные', 12, 16, max_row, 16],
})

f6_x_dx = workbook.add_chart({'type': 'column'})


f6_x_dx.add_series({
    'name':       '=Данные!$R$12',
    'categories':  ['Данные', 12, 0, max_row, 0],
    'values':     ['Данные', 12, 17, max_row, 17],
})

f6_x.add_series({
    'name':       '=Данные!$S$12',
    'categories': ['Данные', 12, 0, max_row, 0],
    'values':     ['Данные', 12, 18, max_row, 18],
})

f6_x_dx.combine(f6_x)


f6_x_dx.set_title({ 'name': 'График 1/5²+x² / 1/5²+x² dx / F(1/5²+x²)'})


worksheet2.insert_chart('K34', f6_x_dx)

########################
# Рендерим график y=eᵡ #
########################

f7_x= workbook.add_chart({'type': 'line'})


f7_x.add_series({
    'name':       '=Данные!$T$12',
    'categories': ['Данные', 12, 0, max_row, 0],
    'values':     ['Данные', 12, 19, max_row, 19],
})

f7_x_dx = workbook.add_chart({'type': 'column'})


f7_x_dx.add_series({
    'name':       '=Данные!$U$12',
    'categories':  ['Данные', 12, 0, max_row, 0],
    'values':     ['Данные', 12, 20, max_row, 20],
})

f7_x.add_series({
    'name':       '=Данные!$V$12',
    'categories': ['Данные', 12, 0, max_row, 0],
    'values':     ['Данные', 12, 21, max_row, 21],
})

f7_x_dx.combine(f7_x)


f7_x_dx.set_title({ 'name': 'График eᵡ / eᵡ dx / F(eᵡ)'})



worksheet2.insert_chart('B50', f7_x_dx)

############################
# Рендерим график y=(x+2)³ #
############################


f8_x= workbook.add_chart({'type': 'line'})


f8_x.add_series({
    'name':       '=Данные!$W$12',
    'categories': ['Данные', 12, 0, max_row, 0],
    'values':     ['Данные', 12, 22, max_row, 22],
})

f8_x_dx = workbook.add_chart({'type': 'column'})


f8_x_dx.add_series({
    'name':       '=Данные!$X$12',
    'categories':  ['Данные', 12, 0, max_row, 0],
    'values':     ['Данные', 12, 23, max_row, 23],
})

f8_x.add_series({
    'name':       '=Данные!$Y$12',
    'categories': ['Данные', 12, 0, max_row, 0],
    'values':     ['Данные', 12, 24, max_row, 24],
})

f8_x_dx.combine(f8_x)


f8_x_dx.set_title({ 'name': 'График (x+2)³ / (x+2)³ dx / F((x+2)³)'})


worksheet2.insert_chart('K50', f8_x_dx)


workbook.close()