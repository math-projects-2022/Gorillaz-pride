Инструкция для пользователя:
Необходимо, чтобы report.py и файл .exe находились в одной папке 
0. Для того чтобы скрипт report.py запустился, необходимо установить библеотеки, описанные в файле requirements.txt.

Используя команды консоли
Unix/macOS/Windows:
python -m pip freeze > requirements.txt
python -m pip install -r requirements.txt
pip freeze > requirements.txt

Установить библеотеки описанные в файле requirements.txt можно так же вручную используя pip install или менеджер пакетов python в Visual Studio.

1. Введите границы интегрирования.
2. Программа запишет результаты вычислений и отрендерит графики в файле отчет.xlsx в папке с программой

