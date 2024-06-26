import os
from demo_recv.classlist import ClassList
from demo_recv.project import Project
from demo_recv.controls import set_controls
from demo_recv.run import run
import demo_recv.models

dir_path = os.path.dirname(os.path.realpath(__file__))
os.environ["RAT_PATH"] = os.path.join(dir_path, '')
