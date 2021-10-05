SELECT description

FROM crime_scene_reports

WHERE day = "28" AND month = "7" AND year = "2020" AND street = "Chamberlin Street"

--getting all the transcriptions from the interviews which happened on the day of crime

SELECT transcript

FROM interviews

WHERE day = "28" AND month = "7" AND year = "2020" AND transcript like "%courthouse%"

--getting activity

SELECT activity

FROM courthouse_security_logs

--people who made a call one minute before crime

SELECT name

FROM people JOIN phone_calls ON people.phone_number = phone_calls.caller

WHERE day = "28" AND month = "7" AND year = "2020" AND duration < "60"

--names of people who make a withdrawl on fifer street

SELECT DISTINCT name

FROM people JOIN bank_accounts ON people.id = bank_accounts.person_id JOIN atm_transactions ON bank_accounts.account_number = atm_transactions.account_number

WHERE day = "28" AND month = "7" AND year = "2020" AND transaction_type = "withdraw" AND atm_location = "Fifer Street"

--people who booked flight on 29

SELECT name

FROM people JOIN passengers ON people.passport_number = passengers.passport_number

WHERE flight_id = (SELECT id FROM flights WHERE day = "29" AND month = "7" AND year = "2020" ORDER BY hour, minute LIMIT 1)

-- getting names on based of license plates of cars that exited courthouse

SELECT name

FROM people JOIN courthouse_security_logs ON people.license_plate = courthouse_security_logs.license_plate

WHERE day = "28" AND month = "7" AND year = "2020" AND hour = "10" AND minute >= "15" AND minute < "25" AND activity = "exit"

--trying to find the theif

SELECT name

FROM people JOIN passengers ON people.passport_number = passengers.passport_number

WHERE flight_id = (SELECT id FROM flights WHERE day = "29" AND month = "7" AND year = "2020" ORDER BY hour,minute LIMIT 1)

INTERSECT

SELECT DISTINCT name

FROM people JOIN bank_accounts ON people.id = bank_accounts.person_id JOIN atm_transactions ON bank_accounts.account_number = atm_transactions.account_number

WHERE day = "28" AND month = "7" AND year = "2020" AND transaction_type = "withdraw" AND atm_location = "Fifer Street"

INTERSECT

SELECT name

FROM people JOIN phone_calls ON people.phone_number = phone_calls.caller

WHERE day = "28" AND month = "7" AND year = "2020" AND duration < "60"

INTERSECT

SELECT name

FROM people JOIN courthouse_security_logs ON people.license_plate = courthouse_security_logs.license_plate

WHERE day = "28" AND month = "7" AND year = "2020" AND hour = "10" AND minute >= "15" AND minute < "25" AND activity = "exit"

--destination

SELECT city

FROM airports

WHERE id = (SELECT destination_airport_id FROM flights WHERE day = "29" AND month = "7" AND year = "2020" ORDER BY hour,minute LIMIT 1)

--person who accompanied

SELECT name

FROM people JOIN phone_calls ON people.phone_number = phone_calls.receiver

WHERE day = "28" AND month = "7" AND year = "2020" AND duration < "60" AND caller = (SELECT phone_number FROM people WHERE name = "Ernest")
