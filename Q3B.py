import sys

def addIfNotInList(l, e):
    b = False
    for i in l:
        if e == i:
            b = True
    if b == False:
        l.append(e)

def getSameElememts(l1, l2, l3):
    l = []
    for i in l1:
        for j in l2:
            if i == j:
                for k in l3:
                    if i == k:
                        l.append(i)
                        return l

def main():
    inp = "rNZNWvMZZmDDmwqNdZrWTqhJMhhgzggBhzBJBchQzzJJ pHlSVbVbFHgHBzzhQHqg nVsqGpbbtDtTNmrmfZ zrBMnbzBchshsttfbMRBgmJggmmCHGgDhDgNDGHL VddZqQqdvSQMJHJGdCDCDDmH pZWWllPQlPZQvZvwpSVlqlvtfswMRzBbntzRbzbfstsRzF NnjjRlnWNSWWbGwccbcchfPfTvfjfTBBpvmdMjTfvB FVzJtDDJDqTMlmlM gVQZlFLlzHhLGShGww rPZtvtFrFPgWjQvCBlcqMzlqQC QGVDJJnLnVTCJBczqqTM fNSSnmLDSVLhhhSNSLhGSGfVPjrFHwmQwtwWFRWRjWPHrwgt SvmlrVrCvmNhSSVZVCrsgqPfbwGFwwwsflbbGb QHffdnHDDQdMGbgqPwztdPds DjBjWHfQDfTQWTBfpMBQLVmmmcCCcVhCBBBhhCmC trLHFFQHTLHJQrflfCnLLHrRfRRPqSRPbPbbsRGqqGqhjj mcMpNWVVNmNVsSbSJPcGhPRR NpzNgwzZDVNZVWNpHJQLQHtQrZQHrBCl JVCMfgJVrJtMBhhrfVVfhVsjvpFGFgjSSgFdSGGqjvjvqF mHllHlHpmWlDSFqbdSTS nmZRLzQnWVpctMVpQs BrvRzWBPWbRwGRjbbRGrtrfqjCJCjCJgJsZJscFCZcJC MnnnVMVhTMQhsccVfwqFJgqf mMShHHppQmHrrBzwtSbWwR pWWGJMJJwlnZSqjWmvSWZC gtHrLttDtgFjjqRZZCrjpp bFtbTpHFHLbfLFbHVttccttddJGQdJzTwdTzJlMnMBwwJJ JhqHFhVMzJPQcdcVncdc NhgfwSjwCWwltSfnrnRWZdpcPrrRnp NNhlltBjssNBgwLFFvDmDqLzHqBB LnFrnddfrLnMFjWzpFhcWpjpFc ntCwgtNggCqCgCqqPPltvcjjhvmWhmvDzTzDzD lqlVQgVCSPVllVQSNGMHHrdQsHrJJBnMHHJf ZGZcRZNWpcHZhJfbbNblrfrgllNr stBMtzCCsHMfFQjfSSPgtt qmszdsCzMncdGwdWZGvH PccqPqbhvSvvvtWNjTtWsWcscp gRwdDzHJQgHzfdRhgHRffzwsTTjTTCjNjssCpmWWDjtCLW zdRMwdRHhGJwgHlnGGSFvvSrnSrr rRpMJtPwrcCTNNQNMZQm mDWdWVddbbbmBflFhvTHjjQjfZTgZgLLfH bhBbFFnDVhdddFBhdmpJRrzStJmwnPzcsJ RjlpRRWzzRGRmGzlCRRlQjCgtvTJTtJrTPttrWTwhFvvVJFT bSBdLLqbcqcLndLHZNqcZdBDPrVTDDTJSFrJJvVthTwwDS cqVsnBfHffVdqnZccGMmCsGzQmjsjlljgz wMzJhLtwbnMWtHcFCCFqFNNbgq fMlMfjrRRmdmGCGVVCHcVqcVTC MmRRRlvmQWzpvnZpwJ gRmgMRMmRwzzmwHbwcTNqPDVBbPTZVqPNZ fWHphpGFpfJrrhPsNTNZVsNVhT WGfJdvltJJfHrJpRgvMRMSwRznwMmw htJFGsGspCppCFCGthCdpmJmgmWZfqqzWzlWcfgZHgzHlg nwVMjVcVcWlbnBlfWB wcNDTvPPDMFJLLppDGDD hjCBgPbvMvmQDzlWnWjm HrHtgZRRRNwczDWwwDzsQQWW LpTqNtFtLFqHLHRrqgFHffVVBChvhhVPBCPhbPbp CwpbCwjGqSjVllpGCllBfhZZRDPNcPPNvLLLDSDN WshFFWsgTHsdMzQvPczLfLZDZRcLfR rWsJQTMhWWHdsQTgsFJgllClVpqVbqnGblCppCVr gRBSGcBDBSJSvPQwrTFLjggQTQ HMMnHHHZfFVFrrMT HhlhppCNcJzCTtBT CCffCCmRLTsQRPHQQMPF dWdbgcDSNclbbdwdSqHsvHPQPTPJplPMFMGJ DWbDNcqZDSWSccNTVBCzVVfmBVZnVz BnsrrvZwBsBSJrrrqSTgJQjCbCjgbCHDJgJFjQ hLmGlnLmGWcjGDgfFFjQdF hhWPmhPtczWpNRmppzRhLchMsnwZvTMZvVSwwrsNwSsBvr tDCCltNVttJhNGlMPSWdqBqSjM RFQcpcRTpFcnFzdLmLSWjMSSBLSQ jwzzczpFbwnHcDCsthDJJsNbst dLRWTHSwTmTwTcTWvQNVVQCvVvNFps GnBPtBMJBPrjGGJMjrlqChNpNlsnhVFhQsVQ JtMtGJfrJgDJjPjRTZLdFcRZRmwSDH VSccPJSBLgZPDLDQ zfpLMmLsHQGqgQHnDD zdLLMssmrdfhddcVdJtScB VvpTVQHSqSHSHqqHJVmRJVHpgDBwDgjcDDDgZjBZBjwBZbRw PCdssGlstdWslFPfNPrtClGjwBgBJgJNwcjBjBgZwwMBJD tlJldhdhdsdhTqSTqVQqQq VGqTcTqbpPwrjfbl BvntnZNNsLZvLszSnCsvJthlfjTrZwlrjrpPlwlhfwrl QBtNtJLvTsFdQcqWmQRR fjcjhmjBvcvcSvcZ HMwZtRQQpGGRgzMvLnWWnbLlSntlbv JQPzzJHqQRqGMMQwHwzDZZhmmPfjDjmjsCZhPj cBlZZMfBrCBMwBMCvQzTwFbQzPnbwjTbTg WtzpVDzmtthzGFQTbTThnnTQQg sGWstpHdpGDmdHdmGmmmJNstRMrCcBSfBSzNBNRrSRNMcMMv mMPDVBZZLSmRdcFpjr fggGGfbfgQStjjsdbtdt gNqQgCQlNCCJgJHvnvnHMjPHjv bLsRQrQsGQbLrbRZMGgbJJBJFtlFFngJphhcfBBq jjdHCCjfVNmmmNDFcBcpBthcplFDFq jmvvmWVjjHTCVvNjSbQGLrRzwMWsMRwfGG sJNCsCFFCNPhCzlrSvRrvwhRjj MMGMTwpMHGzrGczzlG qVmwgHtDtmCdWCsNFmNJ fmhWhjVjNpqRRJjwRw gnGQGDDCgSsCvPlvPgnPgnPtwqbpHRHqHdJpzpQJJJRJRF wgPGsDGPsZgGgBmBWNZNfLWWrZ WdsCVtjWWWHRRqLLHncC fbSpMSPSZHRRcqlpRc cGMmJmfMPPPccZMNQPWvjTtdTjvgmdtTsggw tPBQhHWBtQHgWQCtLwddcGnfpGpwwnbhVb vqQzTNJJJTvRrTNFJsZrrzFlbbfcnVbbcwmGGGpVzmddcdfd NSSqJvFFFFFQjQCjQDSDPD rQZnVVrZmZmgSWqHrSzHPC LGFLwcMBcllBjFNwGjltggSqSWCCzvNgSqSHtt wdhqqGBwwqGMcDhcwdFFbbJppZbssbfZQsQsdVQm lqBZlsjVTbVqmFrSnTFSvwncPP zQztHfZQtWLJzPFnnQScFcFrvS ftHJWHhfttHWffhtgLNfZDWbdqBqjbVssBDCqCdCsmClGG MlbWFTJQFbFFzRdNjNtjdtBT srwnrsLVHzQPQsjjSQ gLpnwgnwnHCvcHHcvwgCvGFFhWGmFmqMMbQFQFFhlGmJ qqNcJgJccdqhsqgsggdgqgcrtfNWNZzVbvVFzttMfzbVMZ GLlpPpCpwPLDGvrFVWrWWbZt DlRCDDLSjTjDjSRSjPClwnwSHHHQmmQvTJcQgvddHsqdcgmB jmRjRbRQLLZbPnbrcTTHHHNn MfhhmmwtvStrpnJJHc fgqlvfhvFzMwqfvMfFWlmMvLZsdQsZVdCdLZdGQjRzdQjD lTPcDlVdTlVVMSDfTJccVzdlmMgGBmppgBmnHGHqHqQqqQMH ZRjWFPsLNLLrPhWNtnBBvnpGpHGpQmHnmR CtwssCNLrsZWjrjcbfPzwJJJffDbTl cjMvvqpJFqhShNCRQR ldtDgQZDPdzztLZgPTtfbnStfBSbNNSbnbhhSS TDsrzsZZZTFHmVHjcsQW BQmQchrmBddcmZZdpSgrpswWWswVsnnnDJVnnZFnGN TfStMPLTHvbvRVGnHGsNnJWFNV qtvMRMMPbbPMLqRPvRTRzMjSSmprpQdBchlmmgldgjzm nRRnvNPhrbZDLjvS HCszMwcHHcLDrbQDWr ptszqwdMbnnhPBqN QbzhhfbFhBbpbzwwLjLJjSjltL mNndGrSStHJTJLln rDMMNVWdVpCbSbSp tDTSTSTTTTJDwqjWqBWttdjg nNPmVfnGfPNVLmNzfnzPVFMjdpBwWZwZHwBLBqgjqpWH dfGPfVQGVPhGzlmnzSvsSTDJhTbTTrrSRD ZfgtZBptBfRQNQggjjrjjwmwsQJPzrwm TwTGGwTwzzsJzTsH lFvwqFLhFMnqcLlVLMLfptNWppppDBDbDfbFgW mjftBfVPjttmjcSjcPttzJlvnrwvTRrTnvwvlRrHHTHRTR WZDWDNLFWbZbcMDWGZDbNdMCRsnTdTvdnqrHCTrvsRRvwC DQFZLNNgtBJQcBzJ HbZQZFVbQVpQplQZGbGchDffltfLtmdgDjggTmtm zWzRCdnCRBRdJrzDjLhDthjLJTTtjq CPPnwSrRdRSzCGMcZZZMwFwMZF WBQqNQnQllwnWQlvBBMlljHTqqFdGfmTdFfcFTFFcqmP rsRRVrZhrzbtpZRRhFDmPvfFFrfTdFHGvc VtSCtSLbtsZVtttthCbJSWSlJlwJQggWWglvwW QfFLWCvRfSLFCtvtFhNcqDDcGVbhGcqh ZVgrdZZPPZZzPwdjzZhmccsqJGqDdsDDNddD pzzwpgZzZZTznZnjZZzPVRLQLlvfSlQRSpWlCvtSQv RtcHhRMcrHhBrrTNDVBNLqLqQqfBPm wCbWzWbvdWCjbWppmtmNmqmLLsfsNV lwjWdbztgHTgggnnnR flBbzbMfbrTlrMvBCcwPggdmcdmg VDVVRFZRZSFFhQLSGFQhjSVZCgpvPwLCzpdWWzccwdvvvwcC hDHRGQVHHQVRZSQGbqqfNTlbHzrbbsqb MTFdTsZpPTcMpFCPdCBmMBmRfRGBmQgQRRgt vbDSwvhzznnbbhDWnvSzRBgQQLgLQltqtqlmwfGB jVjhfSnNDNbzzWzjWSjrCFNpcHdpTTJddJFpsJcc ZrrZPHfChPdDPVVdDq vFmsbTsmSbbBJssmSBvTmmnTrnrwlWqwVlLrVTLLTWqL JrFbpsvFBMBmzBzFStcRhjZjfCCpZNCtct TGgRrTggwwtvtQtdCdQNqN sJHZJVZHDBpFBZBBNzNdhzdpSzddvqhN VZcvFsJVFvsmvssbcnrwbrnGMbMlRn SdcdWzMJdSMWMddZJdVcmBmwrwqrrnVnVNtr mlQHCfgbjsfQTbfCBNtVhVnntVBnVh HLDslDDmblgHfvLHPJFSZPpDFpFFpdPS qNqPNJvcSzGGPQnGQp bWhbgsshZWBhltthhbWtCsZNjrzpnQnnznnjtQFrjGjVFGnn bRDNddhNdDsZdNChmvDmmwqqvLqwSJDq TnSfPnCSmnSgpSTmfLzfMFLWFJJLWWsBsr jdQjcdqDVVwDcPsPzMRJMLqPqR PGhGchjhtZlTGTHCCb ZZRrJJqSqJwNFFphsGsLPJ blcMCflvTTPFFNpVvsFv CcTlltTmtmMdmCmnlllBDDSDQSwSjRDQSdswjR MCCPNsnQFWbvvTPF CcCVJJhjVJZRtcCclDDlbcbTcGFFDz HpjtVwVZfpjJVhZgCVtLmrBwdMrLsNNsMmdLqB TJTDTnrFzzdWgWGJSSMJwg LhPVttjtLmsPqqqVsVpsjLlgWlwHvGnlHWlgHlGgwvlP mQshLhmsnsqZcqhZqpshsLVpNTNbBfzTRBQdFRzNNFBTdbzR ZGqMLGqvJsJsMJmd PDVQPfPcrrcFrrzrTdgCjSSCzgszmlJjBj PfRtVfttVcWtVJrfbGqvwqLpRRwvpppH HmLmMSnnWnrTrnvpqFCHVGfzVFVHQj ttsstRhhcNwbswNtdwsdNPFfjzQppQPjfGGfQVPCpR bbsDNtDcbhstsSZLDmSSgCmnSS tfwBBLcJVrDnqvLv zmWWJRZhWRRRGRNdgSZGgWTvpnjvrDqvpHjjzrpnrPDnHj NdJmSGZWRhRNsghWTJmdGfQCtllCcFMwffBftsfMQc lTLgTghpGZJDBrnGWnnm VlRwlHttwqmHHbDWHJ twldzCvsRdsFFtRtSczTjSgMcfSpSzTM pBpMBTcSlNtMcTfFCmbPDzCDLb JgrjjJqhGZQrQrZhnJGDDCZfvPDdDzFFdzfmZL QHhqqnrVJJPhHrnGQgwMNwMMctcWRWSBMNtNsW FJrlhpcfDCcFWpNpwWwjNQwz RTTvPdbjWzMbnNNM GRZTGggGgtvjGcqrBcttcDlFhr pMRVdVbbMMMSdWWqHpCTvTjnBBBFFGGB smNfZgcsNrcmzggZszsgRnPGFHjBPTBTjGjPTBNj RmwgsmgfrzzsZtfgZLQQSVWlwbdMhlwdqQ mRRjPmLrrSmzSczSzPgVZFpTCpZCMWrZQMQrZJZT BvdbHNdnJtvBDbqqdBlvwvqpDQMpZQFMCsQCspZTMMCZCF nBlfbfbndJBHPfLRfmhhhhPL ScJDFBNLLbVRqVfZ rWrgmdMgnnBhBtnntf CwBWWMgCwddCgwsQjsrvNvlTJzSNHwNTHFJHzS vnddCrNpCgtjLdSdgCgCCvLnWqDhWBQhHqQHDqBhQHDHNNDl wPTVfVTJmZGJVJGffZBwHMWlWlHlWtbQDqbl mGsJVVJsTVTTmtJVzzTJjdSjjprzCvpSLSCjdnLg zLNggsVHmNNsssLmwzLQZLwDRvGQBqGGDDBBvvDBDqPhRG WrCjbtJdbFhBRglGgjqv JWCJcWcSdWcctnJCcJJJbcbmzwwznmgLzNzmLHmHZMwsZL JRRDNNhhszMTzNMwCG MnHPqmgmHjPnnvjqdmjFLQwLwTLwzTwTdGLCzS BnPPZqmcfqgqnnZmBmqjqhfWVJlRMlhWlRDlVsssbh nmTLTqsvqnwqsvwDPnLHdNVrMMHHCBlmVdmGNV RgRpcJhQRfQZcJbWhQpBHCjVCdjCVGdddMllHp fczbZhzbtcZfgRRBcWSPPwFsLSDswSwTsSzw rbFpzFCVBrrBZCjbCzHHBVdJllGDLsLrDtsswswstGJs QNhNNnNnnQhNWSnRhnJtdpJpJtMDGsGLLtsQ ScmRvNRNnWWvNvNvfpTccjVZbqgZgVzqHjCjTVTVVq BTppwCwBpwwBqnjlHcLBTHnbbSbDthsSSJgsnDDRgJRD FVGzzvrdMGSSsdtZtZgd QvQtvtGFlBLLjLQL gsWWsNMjwgPMPWnMjShHHZSZbmZbbmTSnb rlCvVQrCfqffpVjQRqCCvDDTTTmmZhZTmZhThFmhhZZhqb CDDVJpVfrJJVJLMNzMwWwLwj nHrcsZrssPcBPtQJLJtQQCZQpV GFWzNzNFdNbTMMqbGTqTqzqqdLCpfDQCtRVVCLtdCfQsdCCt TlNqGTWFNmMMszhGsmFTWGFzwHnvSjgPgvgSjllBvBnvwPBB mpMggjgMlmtjtGMwZpcSscBlcsSblhsfSdfs zzPVDRrLrCTQNCzNRTVFNLhBhBSqdQbcfSsJBJdbjJfB RPTRPTVNTFzVrHVDCrTHmHtwMvwWMmtwmGjWgvGv rLMcvfHVfMgLFvfNnBBzwRbBwnrGNs dttJjJCtdjmwzwBCRRCqcs TddDQDJDtQJtcJFpPQHPQMvfQlFL LQSqqpqTCSJcsDcqQMMhnnjMjppZhwHZbZ NRtvtmgmvdBffgtVCBWVRgFbPzHbMHbnwwjMPZfHbPjzPP RNtvCvNdgtNNmldgvCFRNVLsQLqJcQGJJrccGSlDLDLr GdwwqqqwGVtjdPvTCplbHTPbPzPTpp RpLmLLpFfNsgTzclhzClThgH ZFsWZLFZJsNsnWsnRsRfnfJQGBttjdGJjBvvwjdpjjttvj tfPzzLrrdrQlTlvn qJRBhNhNGVRBFRTlnJvCmvmJPCCl VVPDNchNMVFGRMFcRVBjsZZcttSLSZzzStcWtZ pTrwTrnjtttjprTSTNTQfcjcgPsPZfPgjdgdsQ mCmCzvzhmJDHzJDbhFCDPsgddcsfcdsbdgVRpdVs zqJzFCDhmqvGhMmCvmGhMCGJnSlnllSBLllLMtNpWtpNBnlt JBhJrFLhGrnJZrlcbffndnggfggf jqmWMGGSsqCsmpjmsDQzlcHgbtdzjjlVfctjHV GWSmSCspCsMSpRmSmqMMCBvFLJLhTTwFhRFLLBTwrv BCdWccqcqpQqrsNgGsWMgfNW lFttLzzLwnfsLrsNsNLG zjNlznlwvRPZnltwvPFnZRCbmjCcqjpcpQcqVVdbdVBm CwTbbCGNFHtHwwjSjJpzjLMdMMzT rscqqVvWgWrZMjrlmSzzmLrM WPqqZnPqgncnBQQVRbCDwRHGSFHPwRNw ZQnZwWjFvdsHwBJltfmfSlsqlJ gPprhMDTpMpPMVNqNRqNlJhltJdJ pLGCcCrgppCrVcMpdzjvzvjLwQQzFjwzHF NmmmvfqcvmLSQhCLvtvL TVlWTZVJZJsFbwWbQQhtQgLFCnSgghLt hZJTJZhwZlRJrJWHVlblMBffmqfdNMjdGdBBqqcH GJJfLfptGqqqnsVqVVjjDnNc mZPSvPmBCdmwdCLDshSbRnnDDhRL gvBrBvPBPPZCTLZmwmrgQdwfTJMHGzHfWffJzFzttHWFzW sBMvmzWzmFmNWJfffZNLfbqZbtZq jRQVRnhhppnVhjgnDLttLqbLqLQfDLss jRRgpGVGhwhnspgpRppwSnBvMMcWvGczGJJHdmHJmJFF VCLHFwHMhLghHHWhFFgWNMMVzmdmbvWdJqBPJPPBppqmBdzm SRTsjGZTsZZnSnGZGqdBmrqPvmqqqsPpmv GvQSGtZSQllVhtLMcLLNMH GsNdWpdVWGSHjFCWCqFFgqngvW mRQTcrLRmZTPRLPZfqqqHbDDDgFvFnvqzQ hfZHrwwmcZRwlLfwlmrRjMJJsVjslVNBGNjpVBBG pllpztRqBBvvGPpG QQhhZQbVcZQTPMWWGbvvbMHM cwgCQCLZChQwwLZVzCrzzqNCzrDqdFPF bgcLPvvpcbdsbpSsHRTCqsRfWfsHRm lZlQtthrnlVMmTHqqqqHSChB rDtlzttnlSNrMtQjZVrcgGDLLddcdcpPgPGJJd jvGbvLLQDSGlRmmSLjlDmRQggFBrMCwWdsBFWBFjdrrWrr PpTfcPZpNTVNpHzTzzzpPJhBcwrrhFsrMdFcMCBFhgMF JTTqdtfzfzJpqffNdTTHGtQRnmDQGGLQQlQRbblD CQQCshCMwgQhMdjWJFBPpbjgmmWj SNNvcGNSZSTDtGDcczJJBmzbjBJjmppbppms cDtfDVNTGGGNNrwLLwHdqLhfLs ngghZCChzhNjjNbbJfdh slPPRLlBBlVRMvRllLLHvcpcdFfJjvdFpfHfcZ RDZPZBLmPVWDVrQtnzSTmgTwmTSg".split()
    total = 0
    list1 = []
    list2 = [] 
    list3 = []
    n = 1
    for i in inp:
        if n == 1:
            list1 = i
        elif n == 2:
            list2 = i
        else:
            list3 = i
            for j in getSameElememts(list1, list2, list3):
                n = ord(j) - ord('A') + 1
                if n <= 26:
                    n = n + 26
                else:
                    n = n - 32
                total = total + n
            n = 0
        n = n + 1
    print(total)


if __name__ == '__main__':
    main()
