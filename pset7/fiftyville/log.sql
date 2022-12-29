-- Keep a log of any SQL queries you execute as you solve the mystery.

--this was the place instructed to start
SELECT description from crime_scene_reports WHERE month = 7 AND day = 28 AND street = 'Chamberlin Street';
--took place at 10:15 am on July 7th at the Chamberlin street courthouse. # witnesses

--i'm going to read what each witness had to say about what they saw
SELECT name, transcript FROM interviews WHERE month = 7 AND day = 28 AND transcript LIKE '%courthouse%';
--witness names Ruth, Eugene, Raymond.

--checking to see the license plate numbers of everyone who left up to ten minutes after the theft
SELECT license_plate FROM courthouse_security_logs WHERE month = 7 AND day = 28 AND hour = 10 AND minute BETWEEN 15 AND 25;

--trying to find the name on file for any or all of the cars that left between 10:15 and 10:25 with a licence plate number
SELECT name FROM people WHERE license_plate IN (SELECT license_plate FROM courthouse_security_logs WHERE month = 7 AND day = 28 AND hour = 10 AND minute BETWEEN 15 AND 25);
--got back a list of 7 different names

--finding the account numbers for everyone who used the atm on fifer street the day of the theft
SELECT account_number FROM atm_transactions WHERE month = 7 AND day = 28 AND atm_location = 'Fifer Street';

--getting person_id from the bank accounts to narrow down who used the atm
SELECT person_id FROM bank_accounts WHERE account_number IN (SELECT account_number FROM atm_transactions WHERE month = 7 AND day = 28 AND atm_location = 'Fifer Street');

--getting the names of the people who used the atm to compare to the licence plate query of names
SELECT name FROM people WHERE id IN (SELECT person_id FROM bank_accounts WHERE account_number IN (SELECT account_number FROM atm_transactions WHERE month = 7 AND day = 28 AND atm_location = 'Fifer Street' AND transaction_type = 'withdraw'));
--got back a list of 8 different names
--there were 4 in common names with the names given from the licence plate query: Elizabeth, Danielle, Russell, Ernest

--selecting the phone numbers that placed calls on july 28th that lasted less than a minute
SELECT caller FROM phone_calls WHERE month = 7 AND day = 28 AND duration < 60;

--getting the names of the people from the previous phone call query and comparing it with the 4 names found in common from the licence plate and atm queries
SELECT name FROM people WHERE phone_number IN (SELECT caller FROM phone_calls WHERE month = 7 AND day = 28 AND duration < 60);
--this resulted in only 2 names for the possible theif: Russell or Ernest

--finding out what the earliest flight on july 29th is
SELECT hour, minute FROM flights WHERE month = 7 AND day = 29 ORDER BY hour;
--the earliest flight leaves at 8:20am

--getting the id of the earliest flight the day after the theft
SELECT id FROM flights WHERE month = 7 AND day = 29 AND hour = 8 AND minute = 20;

--getting the passport numbers of all the passengers on the earliest flight the next day
SELECT passport_number FROM passengers WHERE flight_id = (SELECT id FROM flights WHERE month = 7 AND day = 29 AND hour = 8 AND minute = 20);

--using the passport number i'm finding the names of those passengers to find out if the theif is on that flight
SELECT name FROM people WHERE passport_number IN (SELECT passport_number FROM passengers WHERE flight_id = (SELECT id FROM flights WHERE month = 7 AND day = 29 AND hour = 8 AND minute = 20));
--the only common name with the previous 2 names left was Ernest so he is th thief. Ernest | 5773159633 passport number

--finding the id of the earliest flight going out the day after the theft
SELECT destination_airport_id FROM flights WHERE month = 7 AND day = 29 AND hour = 8 AND minute = 20;

--getting the name of the airport and the city that the flight is landing in
SELECT full_name, city FROM airports WHERE id = (SELECT destination_airport_id FROM flights WHERE month = 7 AND day = 29 AND hour = 8 AND minute = 20);
--it lands in Heathrow Airport | London

--finding the phone number of the person Ernest called to arrage the flight via Ernest's passport number
SELECT receiver FROM phone_calls WHERE month = 7 AND day = 28 AND duration < 60 AND caller = (SELECT phone_number FROM people WHERE passport_number = 5773159633);

--finding the name of his accomplice
SELECT name FROM people WHERE phone_number = (SELECT receiver FROM phone_calls WHERE month = 7 AND day = 28 AND duration < 60 AND caller = (SELECT phone_number FROM people WHERE passport_number = 5773159633));
--the accomplice's name is Bertholdy
