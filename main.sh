
gnome-screenshot -f /home/anshul/Desktop/Programming/WordBlitz/main_img.png
convert main_img.png -crop 420x420+750+450 main_crop.png
gocr -l 100 -C A-Z main_crop.png >input.txt
g++ trie.cpp 
./a.out
python3 draw.py