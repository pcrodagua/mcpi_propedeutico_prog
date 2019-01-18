#include <stdio.h>

// Function Declaration
int display_menu();
void print_grades(double * sum, int size, int row);


int main() {
    int exit = 0;
    int alumnos;

    printf("Alumnos de 1ero: ");
    scanf("%d", &alumnos);
    double frst_sem_students[alumnos][5];
    double frst_sem_students_sum[alumnos];


    printf("\nAlumnos de 2ndo: ");
    scanf("%d", &alumnos);
    double scnd_sem_students[alumnos][4];
    double scnd_sem_students_sum[alumnos];


    printf("\nAlumnos de 3ero: ");
    scanf("%d", &alumnos);
    double thrd_sem_students[alumnos][3];
    double thrd_sem_students_sum[alumnos];


    printf("\nAlumnos de 4to : ");
    scanf("%d", &alumnos);
    double frth_sem_students[alumnos][2];
    double frth_sem_students_sum[alumnos];

    int sem;
    do {
        int option = display_menu();
        switch (option){
            case 1:
                printf("Semestre(1 - 4): ");
                scanf("%d", &sem);
                printf(".::Agregar Alumno::.\n");
                switch (sem){
                    case 1:
                        for (int i = 0; i < sizeof(frst_sem_students) / sizeof(frst_sem_students[0]); ++i) {
                            printf("---Estudiante: %d---\n", i+1);
                            for (int j = 0; j < 5; ++j) {
                                printf("\nCalificacion # %d: ",j+1);
                                scanf("%lf",&frst_sem_students[i][j]);
                                frst_sem_students_sum[i] += frst_sem_students[i][j];
                            }
                        }
                        break;
                    case 2:
                        for (int i = 0; i < sizeof(scnd_sem_students) / sizeof(scnd_sem_students[0]); ++i) {
                            printf("---Estudiante: %d---\n", i+1);
                            for (int j = 0; j < 4; ++j) {
                                printf("\nCalificacion # %d: ",j+1);
                                scanf("%lf",&scnd_sem_students[i][j]);
                                scnd_sem_students_sum[i] += scnd_sem_students[i][j];
                            }
                        }
                        break;
                    case 3:
                        for (int i = 0; i < sizeof(thrd_sem_students) / sizeof(thrd_sem_students[0]); ++i) {
                            printf("---Estudiante: %d---\n", i+1);
                            for (int j = 0; j < 3; ++j) {
                                printf("\nCalificacion # %d: ",j+1);
                                scanf("%lf",&thrd_sem_students[i][j]);
                                thrd_sem_students_sum[i] += thrd_sem_students[i][j];
                            }
                        }
                        break;
                    case 4:
                        for (int i = 0; i < sizeof(frth_sem_students) / sizeof(frth_sem_students[0]); ++i) {
                            printf("---Estudiante: %d---\n", i+1);
                            for (int j = 0; j < 2; ++j) {
                                printf("\nCalificacion # %d: ",j+1);
                                scanf("%lf",&frth_sem_students[i][j]);
                                frth_sem_students_sum[i] += frth_sem_students[i][j];

                            }
                        }
                        break;
                }
                break;
            case 2:
                printf(".::Obtener Reporte::.\n");
                printf("Semestre(1-4):\n");
                scanf("%d", &sem);
                if (sem == 1) {
                    print_grades(frst_sem_students_sum, sizeof(frst_sem_students) / sizeof(frst_sem_students[0]), 5);
                } else if(sem == 2) {
                    print_grades(scnd_sem_students_sum, sizeof(scnd_sem_students) / sizeof(scnd_sem_students[0]), 4);
                } else if(sem == 3) {
                    print_grades(thrd_sem_students_sum, sizeof(thrd_sem_students) / sizeof(thrd_sem_students[0]), 3);
                } else {
                    print_grades(frth_sem_students_sum, sizeof(frth_sem_students) / sizeof(frth_sem_students[0]), 2);
                }
                break;
            case 0:
                exit = -1;
                break;
            default:
                printf("Opcion Invalida");
        }
    } while (exit != -1);
    return 0;
}

int display_menu(){
    int option = -1;
    printf(".:: Menu :..\n");
    printf("1 ... Agregar Calificaciones \n");
    printf("2 ... Obtener Reporte\n");
    printf("0 ... Salir\n");
    printf("Opcion: ");
    scanf("%d", &option);
    return option;
}

void print_grades(double * sum, int size, int row){
    printf(":::Promedio Individual:::\n");
    double avg = 0.0;
    for (int i = 0; i < size; ++i) {
        double avg_ = sum[i]/(double)row;
        printf("Estudiante: %d ... %lf\n", i+1, avg_);
        avg += avg_;
    }
    printf("\n:::Promedio General:::");
    printf("\nPromedio G: %lf \n\n", avg/size);
}


