import xlsxwriter
import numpy as np
import os
import math
 


workbook = xlsxwriter.Workbook('отчет.xlsx')
worksheet = workbook.add_worksheet('Данные')
worksheet2 = workbook.add_worksheet('Графики')

data = np.loadtxt("data.tsv", delimiter='\t')

# Some data we want to write to the worksheet.

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

#y = []
#for i in np.arange(-math.pi, math.pi, 0.1):
#     y.append(math.sin(i))

#x = []
#for i in np.arange(-math.pi, math.pi, 0.1):
#     x.append(i)

# Start from the first cell. Rows and columns are zero indexed.
row = 0
col = 0

worksheet.set_column(0, 8, 40)
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

# Iterate over the data and write it out row by row.
'''for header, header_1,header_2, header_3, header_4, header_5, header_6, header_7, header_8, header_9  in (data_head):
    worksheet.write(row, col,   header)
    worksheet.write(row, col+1, header_1, cell_format)
    worksheet.write(row, col+2, header_2, cell_format)
    worksheet.write(row, col+3, header_3, cell_format)
    worksheet.write(row, col+4, header_4, cell_format)
    worksheet.write(row+1, col, header_5)
    worksheet.write(row+2, col, header_6)
    worksheet.write(row+3, col, header_7)
    worksheet.write_column(row+1, col+1,  data[0], cell_format)
    worksheet.write_column(row+1, col+2,  data[1], cell_format)
    worksheet.write_column(row+1, col+3,  data[2], cell_format)
    worksheet.write_column(row+1, col+4,  data[3], cell_format)
    worksheet.write(row+5, col,    header_8, cell_format)
    worksheet.write(row+5, col+1,  header_9, cell_format)
    worksheet.write_column(row+6, col,  x, cell_format)
    worksheet.write_column(row+6, col+1,  y, cell_format)
'''
 





#chart_sin = workbook.add_chart({'type': 'scatter',  'subtype': 'smooth'})
#chart_sin.add_series({
#   'name':       '=Данные!A1',
#   'values':     '=Данные!$B$2:$B$4',
    

#})
#chart_sin.add_series({
#    'name':       '=Данные!B6',
#    'categories': '=Данные!$A$7:$A$69',
#    'values':     '=Данные!$B$7:$B$69',
    

#})



# Insert the chart into the worksheet.
#worksheet2.insert_chart('H16', chart_sin)


workbook.close()
