# server-multithread

**Descrizione** – Questo è un semplice server TCP client-server. È un web server implementato in C++ su piattaforma UNIX, progettato per gestire più richieste dei client contemporaneamente con un minimo utilizzo della CPU e un pool di thread. Al momento è un server semplice che permette di caricare file di testo sul server tramite richiesta POST e di recuperarli tramite richiesta GET.

---

### ***FUNZIONAMENTO DEL SERVER***

```
1. Utilizzando socket(), creare un socket TCP.
2. Utilizzando bind(), associare il socket all'indirizzo del server.
3. Utilizzando listen(), mettere il socket del server in modalità passiva, in attesa che un client si connetta.
4. Utilizzando accept(), viene stabilita la connessione tra client e server, pronti a trasferire dati.
5. Questa connessione viene quindi inserita nella coda delle richieste del server.
6. Uno dei thread del pool, che in quel momento non è occupato, prende l'elemento in testa della coda e gestisce la richiesta.
7. Risolve il problema dell'uso della CPU con le variabili di condizione dei thread e il problema della memoria condivisa nella sezione critica della CPU con il mutex lock.
```

---

### ***COME ESEGUIRE IL PROGETTO***

```
Per stabilire una connessione tra client e server, compilare prima server.cpp in un terminale e avviare il programma. Per accedere al server si può usare curl dal terminale oppure eseguire lo script bash nella cartella root.
```

```
1. Compilare il server: g++ -pthread -o ./server/tcpServer ./server/tcpServer.cpp
2. Avviare il server: ./server/tcpServer
3. Per il client: è possibile fare richieste GET direttamente dal browser, es. localhost:18000/
   Per richieste POST: es.
   curl -i -X POST localhost:18000/{nome_file_da_caricare}.txt/ \
   -H "Content-Type: text/xml" \
   --data-binary "@{percorso_file_dal_tuo_computer}"
4. In alternativa, è possibile eseguire lo script shell. Prima di eseguirlo, renderlo eseguibile:
   sudo chmod u+x multiClients.bash
```

---

### ***TECNOLOGIE UTILIZZATE***

- **C++**, programmazione socket, reti informatiche e multithreading.
- Librerie utilizzate:

```
<sys/types.h>  --- Definisce una collezione di typedef e strutture
<sys/socket.h> --- Dichiarazioni di costanti, tipi e funzioni per socket
<netinet/in.h> --- Definizioni per la famiglia di protocolli Internet
<arpa/inet.h>  --- Definizioni per operazioni Internet
<netdb.h>      --- Definizioni per operazioni sui database di rete
<unistd.h>     --- Definizioni di costanti simboliche standard e tipi
<pthread.h>    --- Implementazione dei thread e delle loro funzionalità
```

---

### ***OBIETTIVI FUTURI DEL PROGETTO***

- Trasferire dati dei file in modo sicuro da un computer all'altro usando la programmazione socket con architettura client-server.
- Implementare un event loop sul server (asincrono / IO) per proteggerlo da attacchi esterni.

---

### ***AGGIUNTE AL PROGETTO ACM***

- Server web progettato per gestire efficacemente la concorrenza.
- Implementazione di variabile di condizione e coda delle richieste sul server per gestire meglio le richieste in modalità asincrona.
- L’utente può caricare un file o scaricare un file già presente sul server.

---

### ***Screenshot***

&#x20;

---

### **Comando Linux per controllare l’utilizzo della CPU della macchina**

[https://www.ibm.com/docs/en/linux-on-systems?topic=tools-top](https://www.ibm.com/docs/en/linux-on-systems?topic=tools-top)

---

### **Esempio per postare un file sul server**

```
curl -i -X POST localhost:18000/nome-file.txt/ \
-H "Content-Type: text/xml" \
--data-binary "@{percorso_file}"
```

---

