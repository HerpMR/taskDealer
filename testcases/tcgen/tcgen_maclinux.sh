
SCRIPT_DIR=$(dirname $0)
cd $SCRIPT_DIR

# TestCaseGenerator for Mac, Linux
# from hervtea

if [ ! -e a.exe ]; then 
	gcc tcgen.c
fi
a.exe
for i in 1 2 3 4
do
	if [ ! -e case_no$i.txt ]; then
		./a.out case_no$i.txt
		sleep 0.75
	fi
done

rm a.exe
echo Generation Completed..

