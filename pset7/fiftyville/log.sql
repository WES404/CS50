-- Keep a log of any SQL queries you execute as you solve the mystery.

SELECT description FROM crime_scene_reports
where street = "Chamberlin Street" AND day = 28 AND month = 7
-- Searching for any crimes commited on Chamberlin street at july, 28
-- 3 witnees wich mention the courthouse / crime at 10:15 am at the courthouse

SELECT activity, license_plate FROM courthouse_security_logs
where day = 28 AND hour = 10

-- Found 14 logs around 10 am july, 28

SELECT name, transcript FROM interviews
where day = 28 AND month = 7

-- Looking for the 3 witness who were interviewd: Ruth, Eugene and Raymond

-- Ruth says she saw the thief leaving around 10 minutes after out of the courthouse

SELECT people.name, people.license_plate, courthouse_security_logs.activity, courthouse_security_logs.minute,
people.phone_number, people.passport_number,
FROM atm_transactions
INNER JOIN bank_accounts on bank_accounts.account_number = atm_transactions.account_number
INNER JOIN people on people.id = bank_accounts.person_id
INNER JOIN courthouse_security_logs on courthouse_security_logs.license_plate = people.license_plate
where atm_transactions.day = 28 AND courthouse_security_logs.month = 7
AND atm_transactions.atm_location = "Fifer Street" AND transaction_type = "withdraw" and courthouse_security_logs.hour = 10

-- Eugene says the thief was at the ATM withdrawing money earlier in the morning at fifer street
-- 5 people withdraw money at Fifer Street that morning and were in the courthouse and all of them were exiting

Ernest	    94KL13X	exit	18
Russell	    322W7JE	exit	23
Elizabeth	L93JTIZ	exit	21
Danielle	4328GD8	exit	19
Madison	    1106N58	exit	35

-- One of the witness (Ruth) says the thief left around 10 minutes after so we have 4 suspect excluding Madison

-- The last witness says the thief call the accomplice and said to book a flight for the next day

SELECT people.name, people.phone_number,phone_calls.receiver, courthouse_security_logs.activity, courthouse_security_logs.minute
FROM atm_transactions
INNER JOIN bank_accounts on bank_accounts.account_number = atm_transactions.account_number
INNER JOIN people on people.id = bank_accounts.person_id
INNER JOIN courthouse_security_logs on courthouse_security_logs.license_plate = people.license_plate
INNER JOIN phone_calls on phone_calls.caller == people.phone_number
where atm_transactions.day = 28 AND courthouse_security_logs.month = 7
AND atm_transactions.atm_location = "Fifer Street" AND atm_transactions.transaction_type = "withdraw" and courthouse_security_logs.hour = 10
AND phone_calls.day = 28 and phone_calls.duration < 60

-- only 3 people made calls that day and hour last than 1 minute

Ernest	(367) 555-5533	(375) 555-8161	exit	18
Russell	(770) 555-1861	(725) 555-3243	exit	23
Madison	(286) 555-6063	(676) 555-6554	exit	35


Select people.name, flights.destination_airport_id, flights.hour From people
INNER JOIN passengers on passengers.passport_number = people.passport_number
INNER JOIN flights on flights.id = passengers.flight_id
INNER JOIN airports on airports.id = flights.origin_airport_id
WHERE flights.day = 29 AND airports.city = "Fiftyville" and flights.hour < 12

--Only Madison and Ernest took a flight out of towm on 29, july

-- Ernest is probably the thief, he left the courthouse at 10:18 am as one of the witness says. He was
-- at the ATM on Fifer Street as other witness told.
-- He went to London and his accomplice was Berthold

Select people.name, airports.city, flights.hour From people
INNER JOIN passengers on passengers.passport_number = people.passport_number
INNER JOIN flights on flights.id = passengers.flight_id
INNER JOIN airports on airports.id = flights.destination_airport_id
WHERE flights.day = 29 AND airports.id = 4 and flights.hour < 12

Select people.name From people
INNER JOIN phone_calls on phone_calls.receiver = people.phone_number
WHERE phone_calls.receiver = "(375) 555-8161"





