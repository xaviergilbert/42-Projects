python3 -m venv ./django_venv
pip freeze > ~/requirements_python.txt  
cp ~/requirements_python.txt ./django_venv/requirements.txt
source django_venv/bin/activate
pip install -r requirements.txt
pip install --upgrade pip