import os
import shutil

def delete_files(path, suffixes):
    relative_paths = os.listdir(path)
    for relative_path in relative_paths:
        absolute_path = os.path.join(path, relative_path)
        if os.path.isfile(absolute_path):
            for suffix in suffixes:
                if suffix in relative_path:
                    os.remove(absolute_path)
                    break
        elif os.path.isdir(absolute_path):
            delete_files(absolute_path, suffixes)

def delete_tests(path):
    relative_paths = os.listdir(path)
    for relative_path in relative_paths:
        absolute_path = os.path.join(path, relative_path)
        if os.path.isdir(absolute_path):
            if relative_path in ['test', 'Test']:
                shutil.rmtree(absolute_path)
            else:
                delete_tests(absolute_path)

delete_files(os.getcwd(), ['.exe', '.o'])
delete_tests(os.getcwd())