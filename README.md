# Option Musique TD MIDI

## Prérequis
* STM32CubeIDE 1.10.1 (ou supérieur)
    * [https://www.st.com/en/development-tools/stm32cubeide.html\#get-software](https://www.st.com/en/development-tools/stm32cubeide.html\#get-software)
* Ou STM32CubeMX 6.6.1 et VSCode (ou autre IDE)
	* [https://www.st.com/en/development-tools/stm32cubemx.html\#get-software](https://www.st.com/en/development-tools/stm32cubemx.html\#get-software)
* Renoise
    * [https://www.renoise.com/download](https://www.renoise.com/download)

## Récupération du projet
* Clonez ou téléchargez le projet dans un dossier sans espace ni accent

 git clone https://github.com/lfiack/option_musique_td_midi.git

## Importer le projet dans STM32CubeIDE
* Lancez STM32CubeIDE
* File > Import
* General > Existing project into Workspace
* Select root directory > Browse...
* Choisir le dossier option_musique_td_midi
* Cliquez sur Finish

## Tester le projet
* Compilez le projet
* Programmez la carte
* Naviguez dans les différents onglets
* Sur le PC, ouvrez un terminal
* Lancez la commande **lsusb**
* Quelles sont les lignes correspondant à la carte?

### Récupération de la liaison série
* Dans un terminal, lancez minicom
    * Sous Windows, vous pouvez utiliser TeraTerm, Putty ou autre, débrouillez-vous...

 minicom -D /dev/ttyACM0


* Redémarrez la carte (bouton poussoir noir), un prompt devrait apparaître dans minicom
* Tapez 'h' puis **Entrée**
* Testez les différentes fonctions

### Tests avec renoise
* Lancez renoise
* Cliquez sur Edit > Preference, puis sur l'onglet MIDI
* Dans In device C, sélectionnez MIDI Device MIDI 1
* Fermez la fenetre Preference
* Dans renoise, allez dans l'onglet MIDI
* Dans Input Device et dans Output Device, sélectionnez MIDI Device MIDI 1
* Appuyez sur une touche du clavier virtuel
* Quelque chose devrait apparaître dans minicom

* Si le prompt disparaît, vous pouvez le faire réapparaître en appuyant sur **Entrée**

## Analyse du code
* Vous pouvez faire \texttt{Ctrl+Clic} sur une fonction (ou appuyer sur F3)
* Quelles sont les fonctions appelables par le shell?
    * Où sont-elles définies?
* Comment ajouter une fonction au shell?
* Quelles fonctions sont appelées quand un message est envoyé depuis renoise?
* Quelle est la fonction appelée lorsque l'on bouge un slider?

## Ajout de fonctionalités
* Écrivez une fonction shell permettant d'envoyer une commande \texttt{Note On} et \texttt{Note Off}
    * Testez dans renoise
* Modifiez le code pour envoyer des messages \texttt{Control Change} lorsque l'on touche à un slider
    * Testez dans renoise

## Aller plus loin
* Quelques suggestions :
    * Dans renoise, créez un rythme, ajoutez des effets (delay, reverb...), jouez avec les paramètres de ces effets
    * Ajoutez des onglets pour pouvoir contrôler plus de paramètres
    * Créez un clavier dans un nouvel onglet
    * Développez un synthé : utilisez le CODEC audio pour sortir du son
