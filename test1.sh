cd Compiler/
make file=${1}.txt
rm -rf ./tests/${1}.vm
cat vm.vm > ../VM_VMC_Translator/tests/${1}.vm
cd ../VM_VMC_Translator/
python3 main.py ./tests/${1}.vm