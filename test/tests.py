import os

print("[TESTING]")

os.system(os.getcwd()+"/bin/bal.out test/test_files/basic.bl")
print()
os.system(os.getcwd()+"/bin/bal.out test/test_files/factorial.bl")

print("[DONE!]")
