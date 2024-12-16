import React from 'react';
import { StyleSheet, View, Text, TouchableOpacity, Alert, Dimensions } from 'react-native';
import axios from 'axios';

const ESP32_IP = "http://192.168.4.1"; // Adresse IP de l'ESP32
const { width, height } = Dimensions.get('window'); // Taille de l'écran

const sendCommand = async (command) => {
  try {
    await axios.get(`${ESP32_IP}/${command}`);
    Alert.alert("Commande envoyée", `La commande "${command}" a été envoyée avec succès.`);
  } catch (error) {
    Alert.alert("Erreur", "Impossible de contacter le robot.");
    console.error(error);
  }
};

const App = () => {
  const gridSize = 40; // Taille de chaque carré

// Calcul dynamique pour couvrir l'écran en ajoutant une marge supplémentaire
const numColumns = Math.ceil(width / gridSize) + 2; // Ajouter un buffer pour couvrir les bords
const numRows = Math.ceil(height / gridSize) + 2;

return (
  <View style={styles.container}>
    {/* Grille verte */}
    <View style={styles.gridContainer}>
      {Array.from({ length: numRows }).map((_, rowIndex) => (
        <View key={rowIndex} style={{ flexDirection: 'row' }}>
          {Array.from({ length: numColumns }).map((_, colIndex) => (
            <View
              key={`${rowIndex}-${colIndex}`}
              style={{
                width: gridSize,
                height: gridSize,
                borderWidth: 0.5,
                borderColor: '#65B741', // Couleur verte pour les lignes
              }}
            />
          ))}
        </View>
      ))}
    </View>


      {/* Boutons */}
      <View style={styles.buttonContainer}>
        <TouchableOpacity style={styles.button} onPress={() => sendCommand('avance')}>
          <Text style={styles.buttonText}>🚀 Avancer</Text>
        </TouchableOpacity>
        <TouchableOpacity style={styles.button} onPress={() => sendCommand('recule')}>
          <Text style={styles.buttonText}>🔙 Reculer</Text>
        </TouchableOpacity>
        <TouchableOpacity style={styles.button} onPress={() => sendCommand('gauche')}>
          <Text style={styles.buttonText}>↩️ Gauche</Text>
        </TouchableOpacity>
        <TouchableOpacity style={styles.button} onPress={() => sendCommand('droite')}>
          <Text style={styles.buttonText}>↪️ Droite</Text>
        </TouchableOpacity>
        <TouchableOpacity style={styles.button} onPress={() => sendCommand('stop')}>
          <Text style={styles.buttonText}>⏹️ Arrêter</Text>
        </TouchableOpacity>
        <TouchableOpacity style={styles.button} onPress={() => sendCommand('stop')}>
          <Text style={styles.buttonText}>💧 Pschit</Text>
        </TouchableOpacity>
      </View>
    </View>
  );
};

const styles = StyleSheet.create({
  container: {
    flex: 1,
    backgroundColor: '#F5F5F7', // Fond gris clair
    justifyContent: 'center',
    alignItems: 'center',
  },
  gridContainer: {
    position: 'absolute',
    top: 0,
    left: 0,
    flexDirection: 'row',
    flexWrap: 'wrap',
    width: width,
    height: height,
  },
  gridLine: {
    borderColor: '#65B741', // Couleur verte pour les lignes
    borderWidth: 0.5,
  },
  buttonContainer: {
    alignItems: 'center',
    zIndex: 10, 
  },
  button: {
    backgroundColor: '#65B741', 
    borderRadius: 12,
    paddingVertical: 12,
    paddingHorizontal: 30,
    marginVertical: 10,
    shadowColor: '#000',
    shadowOffset: { width: 0, height: 2 },
    shadowOpacity: 0.1,
    shadowRadius: 3,
    elevation: 3,
  },
  buttonText: {
    color: '#FFFFFF',
    fontSize: 18,
    fontWeight: '600',
    textTransform: 'uppercase',
    letterSpacing: 1,
  },
});

export default App;
