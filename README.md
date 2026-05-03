# Customer-Service-Ticket-System
This system is optimized for persistence, bilingual accessibility, and administrative security
Final Documentation: Customer Service Ticket System (CSTS)
Version: 1.1.0 Release Date: 03/05/26
Developer Note: This system is optimized for persistence, bilingual accessibility, and administrative security.(EVAD KEDO)
System Initialization & Language Gate
To ensure immediate accessibility, the system initiates with a Language Gate before displaying any other content.
Startup Prompt: The user is asked to select a language: 1 for Swahili or 2 for English.
Bilingual Implementation: All subsequent menus, category descriptions, and confirmation messages dynamically translate based on this initial choice.
Main Menu Structure
The core interface consists of five primary modules designed to handle all customer interactions and staff oversight:
Create Support Ticket: The engine for generating traceable help requests.
Please Rate Us: A 1–5 feedback loop for service quality assessment.
Language Settings: Allows users to toggle language preferences mid-session.
FAQs: Provides instant answers to common questions to reduce ticket volume.
Administrator Access: A secure portal for staff to manage logs and system data.
Exit Command: Entering 9 terminates the infinite loop and closes the program.
3. Functional Modules
Ticket Generation Logic
Categorization: Users select a letter from A to G (e.g., A for Failed Transactions, B for Billing).
Issue Capture: Users type a description which is stored as a string.
ID Formatting: The system generates a unique ID: [Letter]-[0001]-[03/05/26].
File Persistence: Every ticket is saved to tickets.txt using Append Mode ("a"), ensuring new data never overwrites previous records.
Rating System
Scale: 1 (Very Poor) to 5 (Excellent).
Response: Triggers a "Thank you for your feedback!" message.
4. Security & Administration
The system protects sensitive logs via hardcoded credential validation.
Username: admin.
Password: 1234.
Access: Only successful logins can view the contents of the tickets.txt database.
6. Future Scalability...
The system is designed to allow for additional automated logging and audit trails in future updates.
5. Technical Architecture Summary


1. Persistence Permanent storage in tickets.txt via fprintf
2. Protection Append mode ensures existing data remains safe
3. Logic Gate Language selection happens before the Main Menu loop
4. Input Safety Buffer clearing prevents crashes from non-numeric input
5. Exit Code9 breaks the while(1) loop for a clean shutdown




