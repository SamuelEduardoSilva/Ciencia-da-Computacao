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

namespace BrasilCardAppLojistaXamarin.Droid.Helper
{
    /// <summary>
    /// Classe especializada em gerar a mascara de cartao de credito
    /// </summary>
    public class PhoneMaskHelper : MaskHelper
    {
        /// <summary>
        /// Construtor padrao necessario para inicializar atributos da super classe
        /// </summary>
        /// <param name="editText"></param>
        /// <param name="mask"></param>
        public PhoneMaskHelper(EditText editText) : base(editText, MaskHelper.TELEFONE_MASK)
        {
        }

        /// <summary>
        /// Sobrescreve o metodo da super classe para atender aos dois padroes de mascara de cartao
        /// </summary>
        /// <param name="s">Java.Lang.ICharSequence</param>
        /// <param name="start">int</param>
        /// <param name="before">int</param>
        /// <param name="count">int</param>
        public override void OnTextChanged(Java.Lang.ICharSequence s, int start, int before, int count)
        {

            String telefoneSemMascara = Unmask(s.ToString());

            _mask = (telefoneSemMascara.Length <= 10) ? MaskHelper.TELEFONE_MASK: MaskHelper.CELULAR_MASK;

            base.OnTextChanged(s, start, before, count);
        }
    }
}