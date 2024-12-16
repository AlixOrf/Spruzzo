import React from 'react';
import { StyleSheet, View, Text, TouchableOpacity, Alert, Dimensions } from 'react-native';
import axios from 'axios';

const ESP32_IP = "http://192.168.4.1"; 
const { width, height } = Dimensions.get('window'); 

const sendCommand = async (command) => {
  console.log(`Sending command: ${command}`); 
  try {
    await axios.get(`${ESP32_IP}/${command}`);
    console.log(`Command "${command}" successfully sent to ESP32.`);
    Alert.alert("Commande envoyée", `La commande "${command}" a été envoyée avec succès.`);
  } catch (error) {
    console.error(`Error sending command "${command}":`, error); 
    Alert.alert("Erreur", "Impossible de contacter le robot.");
  }
};

const App = () => {
  const gridSize = 40; 
  const numColumns = Math.ceil(width / gridSize) + 2; 
  const numRows = Math.ceil(height / gridSize) + 2;


  return (
    <View style={styles.container}>

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
                  borderColor: '#65B741', 
                }}
              />
            ))}
          </View>
        ))}
      </View>

      <View style={styles.buttonContainer}>
        <TouchableOpacity 
          style={styles.button} 
          onPress={() => {
            console.log('Button pressed: Avancer');
            sendCommand('avance');
          }}
        >
          <Text style={styles.buttonText}>🚀 Avancer</Text>
        </TouchableOpacity>
        <TouchableOpacity 
          style={styles.button} 
          onPress={() => {
            console.log('Button pressed: Reculer');
            sendCommand('recule');
          }}
        >
          <Text style={styles.buttonText}>🔙 Reculer</Text>
        </TouchableOpacity>
        <TouchableOpacity 
          style={styles.button} 
          onPress={() => {
            console.log('Button pressed: Gauche');
            sendCommand('gauche');
          }}
        >
          <Text style={styles.buttonText}>↩️ Gauche</Text>
        </TouchableOpacity>
        <TouchableOpacity 
          style={styles.button} 
          onPress={() => {
            console.log('Button pressed: Droite');
            sendCommand('droite');
          }}
        >
          <Text style={styles.buttonText}>↪️ Droite</Text>
        </TouchableOpacity>
        <TouchableOpacity 
          style={styles.button} 
          onPress={() => {
            console.log('Button pressed: Stop');
            sendCommand('stop');
          }}
        >
          <Text style={styles.buttonText}>⏹️ Arrêter</Text>
        </TouchableOpacity>
        <TouchableOpacity 
          style={styles.button} 
          onPress={() => {
            console.log('Button pressed: Pompe');
            sendCommand('pompe');
          }}
        >
          <Text style={styles.buttonText}>💧 Pschit</Text>
        </TouchableOpacity>
      </View>
    </View>
  );
};

const styles = StyleSheet.create({
  container: {
    flex: 1,
    backgroundColor: '#F5F5F7',
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
    borderColor: '#65B741',
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
