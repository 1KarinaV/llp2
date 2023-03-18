sudo docker build -t lab .
sudo docker run -v $(pwd):/home/ --rm -it lab
