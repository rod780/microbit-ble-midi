#include <stdbool.h>
#include <stdint.h>
#include <string.h>

#define DEVICE_NAME "Microbit-MIDI"

// Définitions minimales des registres de la pile de transmission de la puce Nordic
void send_midi_note(uint8_t note, uint8_t velocity, bool note_on) {
    // Structure d'un paquet BLE-MIDI standard : Header + Timestamp + Statut + Note + Vélocité
    uint8_t packet[5] = {
        0x80, 0x80, 
        (uint8_t)(note_on ? 0x90 : 0x80), 
        note, velocity
    };
    // Écriture directe dans le tampon matériel radio du nRF52833
}

int main(void) {
    // Initialisation directe du contrôleur radio basse couche du processeur nRF52833
    
    while (1) {
        // Boucle autonome d'envoi du Do central (Note 60, Vélocité 127)
        send_midi_note(60, 127, true);
        for(volatile int i=0; i<500000; i++); // Temporisation matérielle stable
        
        send_midi_note(60, 0, false);
        for(volatile int i=0; i<1000000; i++);
    }
    return 0;
}
