#include <stdio.h>
#include <string.h>

int main() {
    int mainChoice, subChoice, language = 0;
    int ticketNumber = 1;
    char category;
    char issue[100];
    char user[20], pass[20];
    FILE *fptr;

    // --- INITIALIZATION: LANGUAGE GATE ---
    while (language != 1 && language != 2) {
        printf("Chagua lugha: 1. Kiswahili | Select language: 2. English: ");
        if (scanf("%d", &language) != 1) {
            printf("Ingizo batili! / Invalid input!\n");
            while (getchar() != '\n');
        }
    }

    while (1) {
        // --- MAIN MENU TRANSLATION ---
        if (language == 1) {
            printf("\n--- MFUMO WA TIKETI ZA HUDUMA ---");
            printf("\n1. Fungua Tiketi ya Msaada");
            printf("\n2. Tupe Ukadiriaji");
            printf("\n3. Mipangilio ya Lugha");
            printf("\n4. Maswali ya FAQ");
            printf("\n5. Ufikiaji wa Admin");
            printf("\n9. Toka");
            printf("\nChagua: ");
        } else {
            printf("\n--- CUSTOMER SERVICE TICKET SYSTEM ---");
            printf("\n1. Create Support Ticket");
            printf("\n2. Please Rate Us");
            printf("\n3. Language Settings");
            printf("\n4. FAQs");
            printf("\n5. Administrator Access");
            printf("\n9. Exit");
            printf("\nEnter Choice: ");
        }

        if (scanf("%d", &mainChoice) != 1) {
            while (getchar() != '\n');
            continue;
        }

        if (mainChoice == 9) break;

        switch (mainChoice) {
            case 1: // Ticket Creation
                if (language == 1) {
                    printf("\nVipengele: A:Miamala iliyofeli, B:Matatizo ya malipo, C:Maombi ya urejesho, D:Gharama zisizo sahihi, E:Hitilafu, F:Malalamiko, G:Mengineyo\n");
                    printf("Chagua Kitengo (A-G): ");
                } else {
                    printf("\nCategories: A:Failed, B:Billing, C:Refund, D:Charges, E:Errors, F:Complaints, G:Other\n");
                    printf("Select Category (A-G): ");
                }

                scanf(" %c", &category);

                if (language == 1) printf("Elezea tatizo lako: ");
                else printf("Describe your issue: ");

                scanf(" %[^\n]s", issue);

                fptr = fopen("tickets.txt", "a");
                if (fptr != NULL) {
                    fprintf(fptr, "Ticket ID: %c-%04d-03/05/26 | Issue: %s\n", category, ticketNumber++, issue);
                    fclose(fptr);
                    if (language == 1) printf("Tiketi imetengenezwa! ID: %c-%04d-03/05/26\n", category, ticketNumber - 1);
                    else printf("Ticket created successfully! ID: %c-%04d-03/05/26\n", category, ticketNumber - 1);
                }
                break;

            case 2: // Rating
                if (language == 1) printf("\n1=Mbaya sana, 2=Mbaya, 3=Wastani, 4=Nzuri, 5=Nzuri sana\nWeka alama: ");
                else printf("\n1=Very poor, 2=Poor, 3=Average, 4=Good, 5=Excellent\nEnter score: ");

                scanf("%d", &subChoice);
                if (subChoice >= 1 && subChoice <= 5) {
                    if (language == 1) printf("Asante kwa maoni yako!\n");
                    else printf("Thank you for your feedback!\n");
                }
                break;

            case 3: // Language Settings[cite: 1]
                printf("1. Kiswahili\n2. English\nSelect/Chagua: ");
                scanf("%d", &subChoice);
                if (subChoice == 1 || subChoice == 2) language = subChoice;
                break;

            case 4: // FAQs
                if (language == 1) {
                    printf("\n--- MASWALI YA KAWAIDA ---");
                    printf("\n- Urejesho wa pesa huchukua siku 7 za kazi.");
                    printf("\n- Hakikisha mtandao wako uko sawa kabla ya kulipa.\n");
                } else {
                    printf("\n--- FAQs ---");
                    printf("\n- Refunds take 7 business days.");
                    printf("\n- Ensure your network is stable before paying.\n");
                }
                break;

            case 5: // Admin Access[cite: 2]
                if (language == 1) {
                    printf("Jina la mtumiaji: "); scanf("%s", user);
                    printf("Nenosiri: "); scanf("%s", pass);
                } else {
                    printf("Username: "); scanf("%s", user);
                    printf("Password: "); scanf("%s", pass);
                }

                if (strcmp(user, "admin") == 0 && strcmp(pass, "1234") == 0) {
                    if (language == 1) printf("\n--- jopo la utawala ---\nTiketi za hivi karibuni:\n");
                    else printf("\n--- ADMIN PANEL ---\nRecent Tickets:\n");

                    fptr = fopen("tickets.txt", "r");
                    if (fptr != NULL) {
                        char line[150];
                        while (fgets(line, sizeof(line), fptr)) printf("%s", line);
                        fclose(fptr);
                    }
                } else {
                    if (language == 1) printf("Umekataliwa ufikiaji!\n");
                    else printf("Access Denied!\n");
                }
                break;

            default:
                if (language == 1) printf("Chaguo batili! Jaribu tena.\n");
                else printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}
