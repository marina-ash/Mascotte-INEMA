
#include "site-web.h"
#include "led-eyes.h"
#include <FastLED.h>


const char *ssid = "ESP32_Network";
const char *password = "12345678";

WebServer server(80);

const char htmlPage[] PROGMEM = R"rawliteral(
<!DOCTYPE html>
<html lang="fr">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Commande du Robot Mascotte</title>
    <style>
        body {
            font-family: Arial, sans-serif;
            background-color: #eef2f3;
            text-align: center;
            padding: 20px;
        }
        .navbar {
            display: flex;
            justify-content: space-between;
            align-items: center;
            background-color: #6cae4f;
            padding: 15px;
            color: white;
            font-size: 18px;
            position: relative;
        }
        .nav-buttons {
            display: flex;
        }
        .nav-button {
            background: white;
            color: #6cae4f;
            padding: 10px 20px;
            border: none;
            border-radius: 5px;
            cursor: pointer;
            font-weight: bold;
            margin-left: 5px;
        }
        .nav-button:hover {
            background-color: #e0e0e0;
        }
         .position-buttons {
            display: flex;
            justify-content: space-evenly;
            margin-top: 20px;
        }
        .position-button {
            padding: 12px 25px;
            font-size: 18px;
            background-color: #4a8c3a;
            color: white;
            border: none;
            border-radius: 50px;
            cursor: pointer;
            transition: 0.3s;
        }
        .position-button:hover {
            background-color: #6cae4f;
            transform: scale(1.05);
        }
        .position-button:active {
            background-color: #3e7030;
        }
        .control-buttons {
            display: grid;
            grid-template-columns: 1fr 1fr 1fr;
            grid-template-rows: 1fr 1fr 1fr;
            gap: 10px;
            margin-top: 10px;
            width: 100%;
            max-width: 280px;
            margin-left: auto;
            margin-right: auto;
        }
        .control-button {
            display: flex;
            align-items: center;
            justify-content: center;
            width: 70px;
            height: 70px;
            font-size: 30px;
            font-weight: bold;
            background: linear-gradient(135deg, #4a8c3a, #6cae4f);
            color: white;
            border: none;
            border-radius: 50%;
            cursor: pointer;
            transition: 0.3s;
        }
        .control-button:hover {
            transform: scale(1.1);
        }
        .menu-toggle {
            display: none;
            font-size: 24px;
            cursor: pointer;
        }
        @media (max-width: 768px) {
            .nav-buttons {
                display: none;
                flex-direction: column;
                position: absolute;
                top: 60px;
                right: 10px;
                background: #6cae4f;
                width: 150px;
                border-radius: 5px;
            }
            .nav-buttons.show {
                display: flex;
            }
            .nav-button {
                width: 100%;
                margin: 5px 0;
            }
            .menu-toggle {
                display: block;
            }
        }
        .container {
            display: none;
            background: white;
            padding: 30px;
            border-radius: 10px;
            box-shadow: 0px 4px 10px rgba(0, 0, 0, 0.1);
            max-width: 400px;
            margin: 60px auto;
        }
        .container.active {
            display: block;
        }
        .button {
            display: block;
            width: 100%;
            padding: 12px;
            margin: 10px 0;
            background: linear-gradient(135deg, #6cae4f, #4a8c3a);
            color: white;
            border: none;
            border-radius: 8px;
            cursor: pointer;
            font-size: 16px;
            transition: 0.3s;
        }
        .button:hover {
            transform: scale(1.05);
            
        .control-buttons {
            display: grid;
            grid-template-columns: 1fr 1fr 1fr;
            grid-template-rows: 1fr 1fr 1fr;
            gap: 10px;
            margin-top: 10px;
            width: 100%;
            max-width: 280px;
            margin-left: auto;
            margin-right: auto;
        }
        .control-button {
            display: flex;
            align-items: center;
            justify-content: center;
            width: 70px;
            height: 70px;
            font-size: 30px;
            font-weight: bold;
            background: linear-gradient(135deg, #4a8c3a, #6cae4f);
            color: white;
            border: none;
            border-radius: 50%;
            cursor: pointer;
            transition: 0.3s;
        };
        
        }
    </style>
    <script>
        function toggleEyes() {
            fetch('/toggleEyes')
                .then(response => response.text())
                .then(state => {
                    document.getElementById('eyesButton').innerText = state === "ON" ? "Éteindre les Yeux" : "Allumer les Yeux";
                    document.getElementById('eyesButton').className = state === "ON" ? "button red" : "button green";
                });
        }
        function toggleMenu() {
            document.querySelector('.nav-buttons').classList.toggle('show');
        }
        function showMenu(menuId) {
            document.querySelectorAll('.container').forEach(menu => menu.classList.remove('active'));
            document.getElementById(menuId).classList.add('active');
        }
        function showPopup() {
            if (confirm("Voulez-vous vraiment réinitialiser le robot ?")) {
                resetRobot();
            }
        }
        function resetRobot() {
            alert("Le robot a été réinitialisé.");
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
        <button class="button">EMPIEO</button>
        <button class="button">RPPI</button>
        <button class="button">Campus</button>
        <button class="button">Pédagogie</button>
        <button class="button">Questions récurrentes</button>
    </div>
    
    <div id="control" class="container menu">
        <h1>Contrôle du Robot</h1>
        <div class="control-buttons">
            <div class="control-button" style="grid-column: 2; grid-row: 1;">⬆</div>
            <div class="control-button" style="grid-column: 1; grid-row: 2;">⬅</div>
            <div class="control-button" style="grid-column: 2; grid-row: 2;">⏹</div>
            <div class="control-button" style="grid-column: 3; grid-row: 2;">➡</div>
            <div class="control-button" style="grid-column: 2; grid-row: 3;">⬇</div>
        </div>
        <div class="position-buttons">
            <button class="position-button" onclick="setPosition('debout')">Position Debout</button>
            <button class="position-button" onclick="setPosition('assis')">Position Assis</button>
            <button id="eyesButton" class="position-button" onclick="toggleEyes()">Éteindre les Yeux</button>

        </div>
    </div>
    
    <div id="questions" class="container">
        <h1>Questions Fréquentes</h1>
        <ul class="questions-list">
            <li>Quelles sont les spécialités proposées à l'école ?
                <div class="control-icons">
                    <button onclick="playAudio('Quelles sont les spécialités proposées à l\'école ?')">▶️</button>
                    <button onclick="pauseAudio()">⏸️</button>
                </div>
            </li>
            <li>Comment intégrer l'école après le bac ?
                <div class="control-icons">
                    <button onclick="playAudio('Comment intégrer l\'école après le bac ?')">▶️</button>
                    <button onclick="pauseAudio()">⏸️</button>
                </div>
            </li>
            <li>Quelles sont les opportunités de stages et d'alternance ?
                <div class="control-icons">
                    <button onclick="playAudio('Quelles sont les opportunités de stages et d\'alternance ?')">▶️</button>
                    <button onclick="pauseAudio()">⏸️</button>
                </div>
            </li>
            <li>Y a-t-il un programme d'échanges internationaux ?
                <div class="control-icons">
                    <button onclick="playAudio('Y a-t-il un programme d\'échanges internationaux ?')">▶️</button>
                    <button onclick="pauseAudio()">⏸️</button>
                </div>
            </li>
            <li>Quels sont les débouchés après la formation ?
                <div class="control-icons">
                    <button onclick="playAudio('Quels sont les débouchés après la formation ?')">▶️</button>
                    <button onclick="pauseAudio()">⏸️</button>
                </div>
            </li>
            <li>Comment se passe l'admission pour les étudiants étrangers ?
                <div class="control-icons">
                    <button onclick="playAudio('Comment se passe l\'admission pour les étudiants étrangers ?')">▶️</button>
                    <button onclick="pauseAudio()">⏸️</button>
                </div>
            </li>
            <li>Quelles sont les options disponibles en première année ?
                <div class="control-icons">
                    <button onclick="playAudio('Quelles sont les options disponibles en première année ?')">▶️</button>
                    <button onclick="pauseAudio()">⏸️</button>
                </div>
            </li>
        </ul>
    </div>
</body>
</html>
)rawliteral";

bool eyesOn = false;
void setupWebServer() {
    Serial.begin(115200);

    WiFi.softAP(ssid, password);
    Serial.print("Connectez-vous à '"); Serial.print(ssid); Serial.println("' puis accédez à : ");
    Serial.println(WiFi.softAPIP());

    server.on("/", []() { server.send(200, "text/html", htmlPage); });

   server.on("/toggleEyes", []() {
    eyesOn = !eyesOn;
    Serial.print("Nouvel état des yeux après changement : ");
    Serial.println(eyesOn);

    if (eyesOn) {
    Serial.println("Activation des yeux");
    effetRegard();  // Fonction qui gère l'allumage des LEDs
} else {
    Serial.println("Extinction des yeux");
    eteindreYeux(); // Appelle la fonction pour éteindre les LEDs
}


    server.send(200, "text/plain", eyesOn ? "ON" : "OFF");
});

    server.begin();
    Serial.println("Serveur Web lancé");
}

