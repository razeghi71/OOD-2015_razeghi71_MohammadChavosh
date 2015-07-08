cat template_top.html
echo "Enter form title:" 1>&2
read title
echo "<div class=\"page-header text-center\">"
echo "\n<h1>$title</h1>"
echo "</div>"

echo "<form>"
while true
do
	echo "Enter Label:" 1>&2
	read label

	if test "$label" = ""
	then
		break
	fi

	echo "Enter name:" 1>&2
	read name
	echo "Enter Type:" 1>&2
	read type

	if test "$type" = ""
	then
		type=text
	fi


	echo "<div class=\"form-group\">"
	echo "\t<label for=\"$name\">$label</label>"
	echo "\t<input id=\"$name\" class=\"form-control\" type=\"$type\" name=\"$name\">"
	echo "</div>"

	echo "==========================" 1>&2
done
echo "Enter button name:" 1>&2
read btn
echo "<div class=\"text-center\"><button type=\"submit\" class=\"btn btn-default\">$btn</button></div>"
echo "</form>"
cat template_footer.html
