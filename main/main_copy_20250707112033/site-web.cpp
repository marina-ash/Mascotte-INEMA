
#include "site-web.h"
#include "led-eyes.h"
#include <FastLED.h>


const char *ssid = "ESP32_Network";
const char *password = "12345678";

WebServer server(80);

bool eyesOn = true;

const char htmlPage[] PROGMEM = R"rawliteral(
<!DOCTYPE html>
<html lang="fr">
<head>
  <meta charset="UTF-8" />
  <meta name="viewport" content="width=device-width, initial-scale=1.0"/>
  <title>Commande du Robot Mascotte</title>
  <style>
    :root {
      --primary: #6cae4f;
      --primary-dark: #4a8c3a;
      --text-light: #ffffff;
      --text-dark: #333;
    }

    body {
      font-family: Arial, sans-serif;
      background-color: #eef2f3;
      margin: 0;
      padding: 0;
    }

    .navbar {
      display: flex;
      justify-content: space-between;
      align-items: center;
      background-color: var(--primary);
      padding: 15px;
      color: white;
    }

    .menu-toggle {
      display: none;
      font-size: 24px;
      cursor: pointer;
    }

    .nav-buttons {
      display: flex;
      gap: 10px;
    }

    .nav-button {
      background: white;
      color: var(--primary);
      padding: 10px 20px;
      border: none;
      border-radius: 5px;
      cursor: pointer;
      font-weight: bold;
    }

    .nav-button:hover {
      background-color: #e0e0e0;
    }

    .container {
      display: none;
      background: white;
      padding: 30px;
      border-radius: 10px;
      box-shadow: 0px 4px 10px rgba(0, 0, 0, 0.1);
      max-width: 600px;
      margin: 40px auto;
      text-align: center;
    }

    .container.active {
      display: block;
    }

    .button, .position-button {
      display: block;
      width: 100%;
      padding: 12px;
      margin: 10px 0;
      background: linear-gradient(135deg, var(--primary), var(--primary-dark));
      color: white;
      border: none;
      border-radius: 8px;
      font-size: 16px;
      cursor: pointer;
      transition: 0.3s;
    }

    .button:hover, .position-button:hover {
      transform: scale(1.05);
    }

    .questions-list {
      list-style: none;
      padding: 0;
      text-align: left;
    }

    .questions-list li {
      margin-bottom: 15px;
    }

    .control-icons button {
      margin-left: 5px;
      cursor: pointer;
    }

    @media (max-width: 768px) {
      .menu-toggle {
        display: block;
      }

      .nav-buttons {
        display: none;
        flex-direction: column;
        position: absolute;
        top: 60px;
        right: 15px;
        background: var(--primary);
        border-radius: 5px;
        padding: 10px;
      }

      .nav-buttons.show {
        display: flex;
      }

      .nav-button {
        width: 150px;
        color: white;
        background: none;
      }
    }
  </style>

  <script>
    function toggleMenu() {
      document.querySelector('.nav-buttons').classList.toggle('show');
    }

    function showMenu(menuId) {
      document.querySelectorAll('.container').forEach(menu => menu.classList.remove('active'));
      document.getElementById(menuId).classList.add('active');
    }

    function showPopup() {
      if (confirm("Voulez-vous vraiment réinitialiser le robot ?")) {
        alert("Le robot a été réinitialisé.");
      }
    }

    function playAudio(question) {
      console.log("Lecture: " + question);
    }

    function pauseAudio() {
      console.log("Pause audio");
    }

    function sendCommand(type, action) {
      console.log(`Commande envoyée: ${type} - ${action}`);
    }
  </script>
</head>

<body>
  <div class="navbar">
    <span>Robot Mascotte</span>
    <span class="menu-toggle" onclick="toggleMenu()">☰</span>
    <div class="nav-buttons">
      <button class="nav-button" onclick="showMenu('presentation')">Présentation</button>
      <button class="nav-button" onclick="showMenu('control')">Contrôle</button>
      <button class="nav-button" onclick="showMenu('questions')">Questions</button>
      <button class="nav-button" onclick="showPopup()">Reset</button>
    </div>
  </div>

  <div id="presentation" class="container active">
    <h1>Commandes de Présentation</h1>
    <button class="button">Mascotte d'INEMA</button>
    <button class="button">Campus</button>
    <button class="button">EMPIEO</button>
    <button class="button">RPPI</button>
    <button class="button">Questions récurrentes</button>
  </div>

  <div id="control" class="container">
    <h1>Commandes du Robot</h1>

    <h2>Posture</h2>
    <button class="position-button" onclick="sendCommand('position', 'debout')">🧍 Debout</button>
    <button class="position-button" onclick="sendCommand('position', 'assis')">🪑 Assis</button>

    <h2 style="margin-top:2rem;">Yeux</h2>
    <div class="control-section">
  <button class="position-button on" onclick="sendCommand('eyes', 'on')">👁️ Allumer les yeux</button>
  <p class="command-path">Commande : <code>/yeuxOn</code></p>
</div>

<div class="control-section">
  <button class="position-button off" onclick="sendCommand('eyes', 'off')">👁️‍🗨️ Éteindre les yeux</button>
  <p class="command-path">Commande : <code>/yeuxOff</code></p>
</div>
  </div>

  <div id="questions" class="container">
    <h1>Questions Fréquentes</h1>
    <ul class="questions-list">
      <li>Salut ! Tu peux te présenter ?
        <div class="control-icons">
          <button onclick="playAudio('Salut ! Tu peux te présenter ?')">▶️</button>
          <button onclick="pauseAudio()">⏸️</button>
        </div>
      </li>
      <li>Où est situé le campus de Rouen ?
        <div class="control-icons">
          <button onclick="playAudio('Où est situé le campus de Rouen ?')">▶️</button>
          <button onclick="pauseAudio()">⏸️</button>
        </div>
      </li>
      <li>Qu'est-ce qu'on trouve sur le campus ?
        <div class="control-icons">
          <button onclick="playAudio('Qu est-ce qu on trouve sur le campus ?')">▶️</button>
          <button onclick="pauseAudio()">⏸️</button>
        </div>
      </li>
      <li>Qui gère les questions quotidiennes ?
        <div class="control-icons">
          <button onclick="playAudio('Qui gère les questions quotidiennes ?')">▶️</button>
          <button onclick="pauseAudio()">⏸️</button>
        </div>
      </li>
      <li>Quels parcours propose l'école INEMA ?
        <div class="control-icons">
          <button onclick="playAudio('Quels parcours propose l école INEMA ?')">▶️</button>
          <button onclick="pauseAudio()">⏸️</button>
        </div>
      </li>
      <li>Que couvre le parcours EMPIEO ?
        <div class="control-icons">
          <button onclick="playAudio('Que couvre le parcours EMPIEO ?')">▶️</button>
          <button onclick="pauseAudio()">⏸️</button>
        </div>
      </li>
      <li>Que couvre le parcours RPPI ?
        <div class="control-icons">
          <button onclick="playAudio('Que couvre le parcours RPPI ?')">▶️</button>
          <button onclick="pauseAudio()">⏸️</button>
        </div>
      </li>
      <li>Les cours sont-ils en présentiel ou en distanciel ?
        <div class="control-icons">
          <button onclick="playAudio('Les cours sont-ils en présentiel ou en distanciel ?')">▶️</button>
          <button onclick="pauseAudio()">⏸️</button>
        </div>
      </li>
      <li>Est-ce un problème de ne pas avoir de connaissances en amélioration continue et management ?
        <div class="control-icons">
          <button onclick="playAudio('Est-ce un problème de ne pas avoir de connaissances en amélioration continue et management ?')">▶️</button>
          <button onclick="pauseAudio()">⏸️</button>
        </div>
      </li>
      <li>Y a-t-il des projets pendant la formation ?
        <div class="control-icons">
          <button onclick="playAudio('Y a-t-il des projets pendant la formation ?')">▶️</button>
          <button onclick="pauseAudio()">⏸️</button>
        </div>
      </li>
      <li>Est-ce que je peux choisir n'importe quel domaine industriel pour l'alternance ?
        <div class="control-icons">
          <button onclick="playAudio('Est-ce que je peux choisir n importe quel domaine industriel pour l alternance ?')">▶️</button>
          <button onclick="pauseAudio()">⏸️</button>
        </div>
      </li>
      <li>Comment postuler ?
        <div class="control-icons">
          <button onclick="playAudio('Comment postuler ?')">▶️</button>
          <button onclick="pauseAudio()">⏸️</button>
        </div>
      </li>
      <li>Merci ! Qui puis-je contacter pour plus d'informations ?
        <div class="control-icons">
          <button onclick="playAudio('Merci ! Qui puis-je contacter pour plus d informations ?')">▶️</button>
          <button onclick="pauseAudio()">⏸️</button>
        </div>
      </li>
    </ul>
  </div>
</body>
</html>

<script>
  function sendCommand(type, action) {
    const url = `http://192.168.4.1/yeux${action.charAt(0).toUpperCase() + action.slice(1)}`;
    fetch(url)
      .then(response => {
        if (response.ok) {
          console.log(`Commande envoyée : ${url}`);
        } else {
          console.error('Erreur lors de l’envoi de la commande');
        }
      })
      .catch(error => {
        console.error('Erreur réseau :', error);
      });
  }
</script>

)rawliteral";

void setupWebServer() {
    WiFi.softAP(ssid, password);
    Serial.println("Serveur Web en cours de lancement...");
    Serial.print("Adresse IP : ");
    Serial.println(WiFi.softAPIP());

    // Route principale qui sert le HTML
    server.on("/", []() {
        server.send_P(200, "text/html", htmlPage);
    });

    server.on("/yeuxOn", []() {
    eyesOn = true;
    Serial.println("Commande reçue : yeux ON");
    server.send(200, "text/plain", "Yeux allumés");
});

    server.on("/yeuxOff", []() {
        eyesOn = false;
        eteindreYeux();  // <-- C'est ici que tu éteins les LEDs
        Serial.println("Commande reçue : yeux OFF");
        server.send(200, "text/plain", "Yeux éteints");
    });

    server.begin();
}
