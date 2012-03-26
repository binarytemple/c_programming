#include<stdio.h>
#include<locale.h>




void output_locale_ptr(char * locale, char * message) {
  fprintf(stdout, "\nCurrent locale is:%s\n",   setlocale(LC_ALL,NULL)  );
  fprintf(stdout, "Switching to locale :%s\n",   setlocale(LC_ALL,NULL)  );
  setlocale (LC_ALL, locale);

  struct lconv *locale_ptr= NULL; 

  locale_ptr=localeconv();

  printf("Decimal point:                   %s\n",locale_ptr->decimal_point);
  printf("Thousands Separator:             %s\n",locale_ptr->thousands_sep);
  printf("Grouping:                        %s\n",locale_ptr->grouping);
  printf("International Currency Symbol:   %s\n",locale_ptr->int_curr_symbol);
  printf("Currency Symbol:                 %s\n",locale_ptr->currency_symbol);
  printf("Monetary Decimal Point:          %s\n",locale_ptr->mon_decimal_point);
  printf("Monetary Thousands Separator:    %s\n",locale_ptr->mon_thousands_sep);
  printf("Monetary Grouping:               %s\n",locale_ptr->mon_grouping);
  printf("Monetary Positive Sign:          %s\n",locale_ptr->positive_sign);
  printf("Monetary Negative Sign:          %s\n",locale_ptr->negative_sign);
  printf("Monetary Intl Decimal Digits:    %c\n",locale_ptr->int_frac_digits);
  printf("Monetary Decimal Digits:         %c\n",locale_ptr->frac_digits);
  printf("Monetary + Precedes:             %c\n",locale_ptr->p_cs_precedes);
  printf("Monetary + Space:                %c\n",locale_ptr->p_sep_by_space);
  printf("Monetary - Precedes:             %c\n",locale_ptr->n_cs_precedes);
  printf("Monetary - Space:                %c\n",locale_ptr->n_sep_by_space);
  printf("Monetary + Sign Posn:            %c\n",locale_ptr->p_sign_posn);
  printf("Monetary - Sign Posn:            %c\n",locale_ptr->n_sign_posn);
}

int main(void)
{
  output_locale_ptr("C", "C Failsafe mode");
  output_locale_ptr("", "Switching to Default");
  output_locale_ptr("en_GB.utf8", "Switching to Great Britain, en_GB.utf8 ");
}
