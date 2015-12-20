export PS1='nirant@interviewprep$ '
clear
rm -v ./Present
g++ -g -w PresentQuestion.cpp -o Present -std=c++11
./Present
#(./Present) & pid=$! 
#echo $pid
#(sleep 1.0 && kill -9 $pid)
echo 
#rm -v ./Present
