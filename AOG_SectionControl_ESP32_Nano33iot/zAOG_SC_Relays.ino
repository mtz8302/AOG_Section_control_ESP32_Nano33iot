void SetRelays(void)
{
	if (Set.SectNumEnd > 8) {
		for (byte i = 0; i < 8; i++)
		{
			if (bitRead(RelayOUT[0], i) == LOW) {
				digitalWrite(Set.Relay_PIN[i], !Set.SectRelaysON);
			}
			else {
				digitalWrite(Set.Relay_PIN[i], Set.SectRelaysON);
			}
		}
		for (byte i = 8; i < Set.SectNumEnd; i++)
		{
			if (bitRead(RelayOUT[1], (i - 8)) == LOW) {
				digitalWrite(Set.Relay_PIN[i], !Set.SectRelaysON);
			}
			else {
				digitalWrite(Set.Relay_PIN[i], Set.SectRelaysON);
			}
		}
		if (Set.debugmodeRelay) {
			Serial.print("numbSect: "); Serial.print(Set.SectNumEnd);
			Serial.print("  byte Relays 16-8: "); Serial.print(RelayOUT[1]);
			Serial.print("  byte Relays 8-1: "); Serial.println(RelayOUT[0]);
		}
	}
	else
	{
		for (byte i = 0; i < Set.SectNumEnd; i++)
		{
			if (bitRead(RelayOUT[0], i) == LOW) {
				digitalWrite(Set.Relay_PIN[i], !Set.SectRelaysON);
			}
			else {
				digitalWrite(Set.Relay_PIN[i], Set.SectRelaysON);
			}
		}
		//Serial.println(RelayOUT[0]);
	}
}
