import React from 'react';
import { StyleSheet, View, Text } from 'react-native';
import { Button } from 'react-native-elements';
import axios from 'axios';

export default function App() {
  const sendCommand = (command) => {
    console.log(`Commande envoyée : ${command}`);  
    axios.post('http://192.168.1.100/command', { action: command })
      .then(response => {
        console.log(`Réponse du backend :`, response.data); 
      })
      .catch(error => {
        console.error(`Erreur lors de l'envoi de la commande ${command}`, error); 
      });
  };

  return (
    <View style={styles.container}>
      <Text style={styles.title}>Contrôle du Robot</Text>
      <View style={styles.buttonGroup}>
        <Button
          title="Avancer"
          onPress={() => sendCommand('forward')}
          buttonStyle={{ marginHorizontal: 5 }}
        />
        <Button
          title="Reculer"
          onPress={() => sendCommand('backward')} 
          buttonStyle={{ marginHorizontal: 5 }}
        />
        <Button
          title="Tourner Droite"
          onPress={() => sendCommand('right')} 
          buttonStyle={{ marginHorizontal: 5 }}
        />
        <Button
          title="Tourner Gauche"
          onPress={() => sendCommand('left')}  
          buttonStyle={{ marginHorizontal: 5 }}
        />
        <Button
          title="Activer Pompe"
          onPress={() => sendCommand('pump')}
          buttonStyle={{ marginHorizontal: 5 }}
        />
      </View>
    </View>
  );
}

const styles = StyleSheet.create({
  container: {
    flex: 1,
    justifyContent: 'center',
    alignItems: 'center',
    padding: 20,
  },
  title: {
    fontSize: 20,
    fontWeight: 'bold',
    marginBottom: 20,
  },
  buttonGroup: {
    flexDirection: 'row',
    flexWrap: 'wrap',
    justifyContent: 'space-between',
    marginTop: 10,
  },
});
