#include "krb5_locl.h"

RCSID("$Id$");

krb5_error_code
krb5_get_krbhst (krb5_context context,
		 const krb5_data *realm,
		 char ***hostlist)
{
     krb5_error_code err;
     char buf[BUFSIZ];
     char *val;

     memset(buf, 0, sizeof(buf));
     strcpy(buf, "realms ");
     strncat(buf, (char*)realm->data, realm->length);
     strcat(buf, " kdc");

     err = krb5_get_config_tag (context->cf, buf, &val);
     if (err)
	  return err;
     *hostlist = malloc (2 * sizeof (char *));
     (*hostlist)[0] = val;
     (*hostlist)[1] = NULL;
     return 0;
}

krb5_error_code
krb5_free_krbhst (krb5_context context,
		  char *const *hostlist)
{
     free ((void*)hostlist);
     return 0; /* XXX */
}
