##!/bin/bash


rm -rf ~/Library/Containers/com.docker.docker
mkdir -p ~/goinfre/Docker/Data
ln -s ~/goinfre/Docker ~/Library/Containers/com.docker.docker

if !(docker ps) &>/dev/null; then
  open -a Docker
else
  echo "Docker is running"
fi


while true; do
  if docker ps &>/dev/null; then
    echo "Docker is ready to work."
    break
  else
    echo "Docker is not ready to work..."
    sleep 1
  fi
done


cd ../
docker rmi -f school21/miniverter:1.0
docker build . -t school21/miniverter:1.0 -f valgrind_tests/Dockerfile
container_id=$(docker run -td school21/miniverter:1.0)
docker logs -f "$container_id"

##docker run -p 80:80 -td --name miniverter-container -it school21/miniverter:1.0 // Keep session alive
