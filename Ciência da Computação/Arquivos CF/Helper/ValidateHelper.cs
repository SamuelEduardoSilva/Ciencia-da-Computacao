using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

using Android.App;
using Android.Content;
using Android.OS;
using Android.Runtime;
using Android.Views;
using Android.Widget;
using System.Text.RegularExpressions;

namespace BrasilCardAppLojistaXamarin.Droid.Helper
{
    /// <summary>
    /// Classe que auxilia na validacao
    /// </summary>
    public class ValidateHelper
    {
        /// <summary>
        /// Campo obrigatorio
        /// </summary>
        /// <param name="input"></param>
        /// <param name="valor"></param>
        /// <param name="mensagemErro"></param>
        /// <returns></returns>
        public static bool ValidarStringObrigatoria(Android.Support.Design.Widget.TextInputLayout input, string valor, int mensagemErro)
        {
            bool valido = true;

            if (String.IsNullOrEmpty(valor)) {

                valido = false;
                input.ErrorEnabled = true;
                input.Error = Application.Context.Resources.GetString(mensagemErro);
            }
            else {
                input.ErrorEnabled = false;
            }

            return valido;
        }

        

        /// <summary>
        /// Email valido
        /// </summary>
        /// <param name="input"></param>
        /// <param name="valor"></param>
        /// <param name="mensagemErro"></param>
        /// <returns></returns>
        public static bool ValidarEmail(Android.Support.Design.Widget.TextInputLayout input, string valor, int mensagemErro)
        {
            bool valido = (!String.IsNullOrEmpty(valor));

            if (!valido) {

                input.ErrorEnabled = true;
                input.Error = Application.Context.Resources.GetString(Resource.String.campo_obrigatorio);
            }
            else {

                Regex rg = new Regex(@"^[A-Za-z0-9](([_\.\-]?[a-zA-Z0-9]+)*)@([A-Za-z0-9]+)(([\.\-]?[a-zA-Z0-9]+)*)\.([A-Za-z]{2,})$");

                valido = rg.IsMatch(valor);

                if (!valido) {

                    input.ErrorEnabled = true;
                    input.Error = Application.Context.Resources.GetString(mensagemErro);
                }
                else {

                    input.ErrorEnabled = false;
                }
            }

            return valido;
        }

        /// <summary>
        /// Valida se duas strings são iguais
        /// </summary>
        /// <param name="input"></param>
        /// <param name="valor"></param>
        /// <param name="valorComparacao"></param>
        /// <param name="mensagemErro"></param>
        /// <returns></returns>
        public static bool ValidarIguais(Android.Support.Design.Widget.TextInputLayout input, string valor, string valorComparacao, int mensagemErro) {

            bool valido = (!String.IsNullOrEmpty(valor));

            if (!valido) {

                input.ErrorEnabled = true;
                input.Error = Application.Context.Resources.GetString(Resource.String.campo_obrigatorio);
            }
            else {

                valido = valor.Equals(valorComparacao);

                if (!valido) {

                    input.ErrorEnabled = true;
                    input.Error = Application.Context.Resources.GetString(mensagemErro);
                }
                else {

                    input.ErrorEnabled = false;
                }
            }

            return valido;
        }
    }
}