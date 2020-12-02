#Name: Carson Hom
#Date: Thursday 9:15
#Title: Lab1 -task
#Description: This program outputs information about the user, filepath, line count and number of users as well as calculating the area of a rectangle and circle
#sample shell programs for Lab assignment
#!/bin/sh
echo Executing $0
echo $(/bin/ls | wc -l) files
wc -l $(/bin/ls)
echo "HOME="$HOME
echo "USER="$USER
echo "PATH="$PATH
echo "PWD="$PWD
echo "\$\$"=$$
user=`whoami`
numusers=`who | wc -l`
echo "Hi $user! there are $numusers logged on."
if [ $user = "chom" ]
then
	echo "Now you can proceed!"
else
	echo "Check who logged in!"
	exit 1
fi

response="Yes"
while [ $response != "No" ]
do
	echo "Enter height of rectangle: "
	read height
	echo "Enter width of rectangle: "
	read width
	area=`expr $height \* $width`
	echo "The area of the rectangle is $area"

	echo "Would you like to repeat for another rectangle [Yes/No]?"
	read response
done

echo "Enter radius of circle: "
read r
rsq=$(($r*$r))
carea=`echo "3.14*$rsq" | bc`
echo "The area of the circle is $carea"
