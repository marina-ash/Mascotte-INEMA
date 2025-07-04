# 🤖 Mascotte Interactive pour INEMA

Bienvenue dans le dépôt officiel de la mascotte robotisée d’INEMA !  
Ce projet mêle **robotique**, **web**, et **intelligence artificielle** pour créer un compagnon interactif qui **présente l’école** de façon ludique et innovante lors des **Journées Portes Ouvertes**, salons étudiants et autres événements.

---

## 🎯 Objectif du projet

L’objectif de la mascotte est de :

- 🗣️ **Présenter les formations, l’ambiance et les valeurs d’INEMA** aux futurs étudiants.
- 🤝 **Créer une interaction amusante et mémorable** lors des visites.
- 🚀 **Rendre l’école plus attractive** grâce à une technologie accessible et originale.

La mascotte **parle**, **écoute**, **bouge**, **réagit à distance via une interface web**, et **répond aux questions fréquentes** des visiteurs.

---

## 🖥️ Application Web de Contrôle

L'application web est divisée en plusieurs onglets :

### 🧾 Page "Présentation"
> Cette page affiche toutes les **présentations vocales et visuelles** que la mascotte peut effectuer.  
> Exemple : _"Bienvenue chez INEMA !", "Voici nos parcours de formation", "Les métiers que nous préparons", etc._

- 🎙️ L’utilisateur peut **lancer des messages audio**.
- 📜 Possibilité d’**ajouter/modifier les présentations**.

---

### 🎮 Page "Contrôle"
> Cette section permet de **piloter la mascotte** en temps réel.

Fonctionnalités :
- 🧍 Boutons **Debout / Assis** pour les mouvements du robot.
- 👁️ Contrôle des **LEDs des yeux** : allumer, éteindre, clignoter.
- 🔊 Lancer des **réponses audio** manuellement.
- 🔄 **Bouton RESET** pour remettre le robot dans son état initial (avec confirmation).

---

### ❓ Page "FAQ Étudiant"
> Liste des **questions fréquemment posées par les visiteurs** lors des Journées Portes Ouvertes.

Exemples de questions :
- "Quels sont les débouchés après INEMA ?"
- "Y a-t-il de l’alternance ?"
- "Est-ce qu’on peut venir d’un bac techno ?"
- "Y a-t-il des activités étudiantes ?"

🎤 Le robot peut répondre **automatiquement ou manuellement** à ces questions.

---

## ⚙️ Technologies utilisées

- 🧠 ESP32 (contrôle des composants physiques)
- 🌐 Interface Web en HTML/CSS/JS (avec communication vers l’ESP32)
- 🔊 Module audio + haut-parleur
- 💡 LEDs WS2812B (yeux)
- 🤖 Servomoteurs (mouvements)
- 🔌 Batterie rechargeable + bouton ON/OFF

---

## 📦 Structure du projet

