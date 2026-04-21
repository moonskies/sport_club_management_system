**Sport Club Management System**

An OOP-based C++ application designed to manage sports facility operations, including field reservations, equipment rentals, and spectator logistics. The project follows an N-Tier architecture to ensure modularity and clean separation of concerns.
________________________________________
**Core Features**
•	Field Management: Reserve specific field types with options for public or private matches.

•	Equipment Rental: Integrated inventory system that validates rentals against active field reservations.

•	Match Discovery: System for users to join existing public matches or view available player slots.

•	Spectator Logic: Functionality to spectate matches, with specific pricing logic for private vs. public events.

•	Asset Tracking: Monitoring system for the condition and occupancy of club resources.

________________________________________
**System Architecture**
Domain Layer (Entities)
•	User: Stores identity and links to reserved field and equipment IDs.

•	Field: Tracks type, maintenance condition, and occupancy.

•	Equipment: Manages gear type, condition, and quantity.

•	Polymorphism: Implemented between Field and Equipment assets for shared management logic.


**Repository Layer**
Provides data persistence using std::vector containers for Users, Fields, and Equipment.

**Controller Layer**
Handles business logic, including reservation validation, equipment assignment, and availability tables.

**UI Layer**
Console-based interface for user interaction and system navigation

 
