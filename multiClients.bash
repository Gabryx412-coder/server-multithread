#!/bin/bash

for N in {1..10}
do
    #per i client ruby
    time ruby ./client/mainClient.rb test_file
    #client in c++
    # ./client/client
    #quanto sopra creerà connessioni simultanee con server con processi diversi.

  #   curl -X GET \
  # -H "Content-type: application/json" \
  # -H "Accept: application/json" \
  # "http://localhost:18000/"
  
done
wait