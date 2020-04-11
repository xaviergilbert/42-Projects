from local_lib.path import Path

if __name__ == '__main__':
    d = Path('./new_folder').mkdir_p() #
    f = Path('./new_folder/new_file.txt').touch()
    f.open() #read the file (default)
    f.write_text("Hello World!\n", append=True)
    print(f.text())